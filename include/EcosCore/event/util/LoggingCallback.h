// EcosCore/event/util/LoggingCallback.h
#ifndef ECOSCORE_EVENT_UTIL_LOGGING_CALLBACK_H
#define ECOSCORE_EVENT_UTIL_LOGGING_CALLBACK_H

#include "EcosCore/event/EventCallback.h"
#include "EcosCore/event/CallbackPhaseState.h"
#include "EcosCore/event/CallbackResultState.h"
#include "EcosCore/event/EventContext.h"
#include "EcosCore/state/BaseState.h"
#include "EcosCore/state/TemplateState.h"
#include "ILogger.h"
#include "DebugLogger.h"

#include <typeinfo>

namespace ecoscore::event::util {

    template <typename EventT>
    class LoggingCallback : public ecoscore::state::TemplateState<LoggingCallback<EventT>, ecoscore::state::BaseState>,
        public IEventCallback {
    public:
        explicit LoggingCallback(const ILogger& logger = DebugLogger::instance())
            : logger_(logger) {
        }

        static const LoggingCallback& instance() {
            static LoggingCallback inst(DebugLogger::instance());
            return inst;
        }

        const ecoscore::state::BaseState* Phase() const override {
            return &BeforePhase::instance();
        }

        const ecoscore::state::BaseState* Priority() const override {
            return &DefaultPriority::instance();
        }

        const CallbackResultState& Invoke(const Event& event, EventContext& ctx) const override {
            if (auto derived = dynamic_cast<const EventT*>(&event)) {
                logger_.Log(typeid(*derived).name(), "Event received");
            }
            return Continue::instance();
        }

    private:
        const ILogger& logger_;
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_LOGGING_CALLBACK_H
