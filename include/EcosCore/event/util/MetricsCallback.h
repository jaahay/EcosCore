// EcosCore/event/util/MetricsCallback.h
#ifndef ECOSCORE_EVENT_UTIL_METRICS_CALLBACK_H
#define ECOSCORE_EVENT_UTIL_METRICS_CALLBACK_H

#include "EcosCore/event/EventCallback.h"
#include "EcosCore/event/CallbackResultState.h"
#include "EcosCore/event/EventContext.h"
#include "EcosCore/state/TemplateState.h"

#include <atomic>
#include <iostream>
#include <typeinfo>

namespace ecoscore::event::util {

    template <typename EventT>
    class MetricsCallback : public IEventCallback,
        public ecoscore::state::TemplateState<MetricsCallback<EventT>, ecoscore::state::BaseState> {
    private:
        MetricsCallback() : count_(0) {}

    public:
        static MetricsCallback& instance() {
            static MetricsCallback inst;
            return inst;
        }

        const ecoscore::state::BaseState* Phase() const override {
            return &AfterPhase::instance();
        }

        const ecoscore::state::BaseState* Priority() const override {
            return &DefaultPriority::instance();
        }

        const CallbackResultState& Invoke(const Event& event, EventContext& ctx) const override {
            if (dynamic_cast<const EventT*>(&event)) {
                ++count_;
                std::cout << "[METRICS] Event " << typeid(EventT).name() << " count: " << count_.load() << "\n";
            }
            return Continue::instance();
        }

        int GetCount() const { return count_.load(); }

    private:
        mutable std::atomic<int> count_;
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_METRICS_CALLBACK_H
