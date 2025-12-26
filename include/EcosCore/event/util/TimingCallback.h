// EcosCore/event/util/TimingCallback.h
#ifndef ECOSCORE_EVENT_UTIL_TIMING_CALLBACK_H
#define ECOSCORE_EVENT_UTIL_TIMING_CALLBACK_H

#include "EcosCore/event/EventCallback.h"
#include "EcosCore/event/CallbackResultState.h"
#include "EcosCore/event/EventContext.h"
#include "EcosCore/state/TemplateState.h"
#include "ILogger.h"

#include <chrono>
#include <iostream>
#include <typeinfo>

namespace ecoscore::event::util {

    template <typename EventT>
    class TimingCallback : public ecoscore::state::TemplateState<TimingCallback<EventT>, ecoscore::state::BaseState>, IEventCallback {
    public:
        explicit TimingCallback(const ILogger& logger)
            : logger_(logger) {
        }

        static const TimingCallback& instance() {
            static TimingCallback inst(util::ConsoleLogger::instance());
            return inst;
        }

        const ecoscore::state::BaseState* Phase() const override {
            return &AfterPhase::instance();
        }

        const ecoscore::state::BaseState* Priority() const override {
            return &DefaultPriority::instance();
        }

        const CallbackResultState& Invoke(const Event& event, EventContext& ctx) const override {
            if (auto derived = dynamic_cast<const EventT*>(&event)) {
                auto start = std::chrono::steady_clock::now();

                // Ideally, wrap actual callback invocation here to measure real duration

                auto end = std::chrono::steady_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

                logger_.Log(typeid(*derived).name(), "Callback duration: " + std::to_string(duration) + "us");
            }
            return Continue::instance();
        }

    private:
        const ILogger& logger_;
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_TIMING_CALLBACK_H
