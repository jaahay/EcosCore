// EcosCore/event/helpers/LoggingCallbackRegistration.h
#ifndef ECOSCORE_EVENT_HELPERS_LOGGING_CALLBACK_REGISTRATION_H
#define ECOSCORE_EVENT_HELPERS_LOGGING_CALLBACK_REGISTRATION_H

#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/event/CallbackPhaseState.h"
#include "EcosCore/event/CallbackPriorityState.h"

namespace ecoscore::event::helpers {

    template <typename EventT>
    inline CallbackHandle RegisterDefaultLoggingCallback(EventDispatcher& dispatcher) {
        return dispatcher.AddCallback<EventT>(
            util::LoggingCallback<EventT>::instance(),
            BeforePhase::instance(),
            DefaultPriority::instance()
        );
    }

} // namespace ecoscore::event::helpers

#endif // ECOSCORE_EVENT_HELPERS_LOGGING_CALLBACK_REGISTRATION_H
