// File: ecoscore/event/helpers/LoggingCallbackRegistration.h
// EcosCore/event/helpers/LoggingCallbackRegistration.h
#ifndef ECOSCORE_EVENT_HELPERS_LOGGINGCALLBACKREGISTRATION_H
#define ECOSCORE_EVENT_HELPERS_LOGGINGCALLBACKREGISTRATION_H

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/util/LoggingCallback.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"

namespace EcosCore::event::helpers {

    /**
     * Registers the default logging callback for an event type.
     */
    template <typename EventT>
    inline EcosCore::event::core::CallbackHandle RegisterDefaultLoggingCallback(EcosCore::event::core::EventDispatcher& dispatcher) {
        return dispatcher.AddCallback<EventT>(
            EcosCore::event::util::LoggingCallback<EventT>::instance(),
            EcosCore::tag::Before::instance(),
            EcosCore::tag::Medium::instance()
        );
} // namespace EcosCore::event::helpers

} // namespace EcosCore::event::helpers

#endif // ECOSCORE_EVENT_HELPERS_LOGGINGCALLBACKREGISTRATION_H
