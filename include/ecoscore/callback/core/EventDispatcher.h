// EcosCore/event/core/EventDispatcher.h
#ifndef ECOSCORE_EVENT_CORE_EVENT_DISPATCHER_H
#define ECOSCORE_EVENT_CORE_EVENT_DISPATCHER_H

#include <unordered_map>
#include <memory>
#include <mutex>
#include <vector>
#include <functional>
#include <iostream>

#include "EcosCore/event/core/CallbackManagerKey.h"
#include "EcosCore/event/core/IEventCallback.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/event/core/CallbackHandle.h"
#include "EcosCore/tag/Tag.h"
#include "EcosCore/tag/ResultTags.h"
#include "EcosCore/event/core/InternalFallbackCallbacks.h"

namespace EcosCore::event::core {

    class EventDispatcher {
    public:
        EventDispatcher() {
            AddFallbackCallback(internal_fallbacks::LoggingFallback);
            AddFallbackCallback(internal_fallbacks::MetricsFallback);
            AddFallbackCallback([](const Event& event, const EventContext& ctx) {
                auto& non_const_ctx = const_cast<EventContext&>(ctx);
                internal_fallbacks::DefaultCancellationFallback(event, non_const_ctx);
                });
        }

        template <
            typename EventType,
            typename PhaseTag,
            typename PriorityTag
        >
        CallbackHandle AddCallback(std::function<void(const EventType&)> callback,
            const PhaseTag& phase,
            const PriorityTag& priority) {
            const CallbackManagerKey key{
                EventType::instance(),
                phase,
                priority
            };

            std::lock_guard lock(mutex_);

            if (!managers_.contains(key)) {
                managers_[key] = std::make_unique<CallbackManager<EventType, PhaseTag, PriorityTag>>();
            }

            auto* manager = static_cast<CallbackManager<EventType, PhaseTag, PriorityTag>*>(managers_[key].get());
            auto handle = manager->RegisterCallback({ phase, priority, std::move(callback) });
            handle_to_key_[handle] = key;

            return handle;
        }

        void RemoveCallback(CallbackHandle handle) {
            std::lock_guard lock(mutex_);
            auto it = handle_to_key_.find(handle);
            if (it == handle_to_key_.end()) return;

            auto mit = managers_.find(it->second);
            if (mit != managers_.end()) {
                mit->second->RemoveCallback(handle);
            }

            handle_to_key_.erase(it);
        }

        template <typename EventType, typename PhaseTag>
        void Dispatch(const EventType& event, const PhaseTag& phase) {
            EventContext ctx;

            std::vector<IEventCallback*> relevant_managers;

            {
                std::lock_guard lock(mutex_);
                for (auto& [key, manager] : managers_) {
                    if (&key.event_id == &EventType::instance()
                        && &key.phase_id == &phase) {
                        relevant_managers.push_back(manager.get());
                    }
                }
            }

            for (auto* manager : relevant_managers) {
                manager->Dispatch(event, ctx);
                if (ctx.IsCanceled()) break;
            }

            if (ctx.IsCanceled() || ctx.GetResult() == EcosCore::tag::Stop::instance()) {
                for (auto& fallback : fallback_callbacks_) {
                    fallback(event, ctx);
                }
            }
        }

        // Utility callback registration helpers

        template <typename EventT>
        CallbackHandle RegisterDefaultSerializationCallback(const tag::Phase& phase = tag::Before::instance(),
            const tag::Priority& priority = tag::Medium::instance()) {
            return AddCallback<EventT>(
                [serializer = defaultSerializer_](const EventT& event, EventContext&) {
                    serializer.Serialize(typeid(EventT).name(), &event);
                },
                phase,
                priority);
        }

        template <typename EventT>
        CallbackHandle RegisterDefaultMetricsCallback(const tag::Phase& phase = tag::Before::instance(),
            const tag::Priority& priority = tag::Medium::instance()) {
            return AddCallback<EventT>(
                [collector = defaultMetricsCollector_](const EventT& event, EventContext&) {
                    collector.IncrementEventCount(typeid(EventT).name());
                },
                phase,
                priority);
        }

        template <typename EventT>
        CallbackHandle RegisterDefaultTimingCallback(const tag::Phase& phase = tag::Before::instance(),
            const tag::Priority& priority = tag::Medium::instance()) {
            return AddCallback<EventT>(
                [timer = defaultTimer_](const EventT& event, EventContext&) {
                    timer.Start();
                    // User should call Stop() appropriately after processing
                    timer.Stop();
                    timer.LogElapsed(typeid(EventT).name());
                },
                phase,
                priority);
        }

        // Setters for default utilities (allow user overrides)
        void SetDefaultSerializer(const event::util::ISerializer& serializer) {
            defaultSerializer_ = serializer;
        }

        void SetDefaultMetricsCollector(event::util::IMetricsCollector& collector) {
            defaultMetricsCollector_ = collector;
        }

        void SetDefaultTimer(event::util::ITimer& timer) {
            defaultTimer_ = timer;
        }

    private:
        std::unordered_map<CallbackManagerKey, std::unique_ptr<IEventCallback>> managers_;
        std::unordered_map<CallbackHandle, CallbackManagerKey> handle_to_key_;
        std::vector<std::function<void(const Event&, const EventContext&)>> fallback_callbacks_;
        std::mutex mutex_;

        void AddFallbackCallback(std::function<void(const Event&, const EventContext&)> cb) {
            fallback_callbacks_.push_back(std::move(cb));
        }

        // Default utility instances
        SimpleConsoleSerializer defaultSerializer_;
        ConsoleMetricsReporter defaultMetricsCollector_;
        SteadyClockTimer defaultTimer_;
    };

} // namespace EcosCore::event::core
