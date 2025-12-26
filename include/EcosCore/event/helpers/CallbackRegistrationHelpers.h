// EcosCore/event/helpers/CallbackRegistrationHelpers.h
#ifndef ECOSCORE_EVENT_HELPERS_CALLBACK_REGISTRATION_HELPERS_H
#define ECOSCORE_EVENT_HELPERS_CALLBACK_REGISTRATION_HELPERS_H

#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/CallbackPhaseState.h"
#include "EcosCore/event/CallbackPriorityState.h"

#define ECOSCORE_REGISTER_CALLBACK(dispatcher, EventType, callback) \
    dispatcher.AddCallback<EventType>(callback, \
        ecoscore::event::BeforePhase::instance(), \
        ecoscore::event::DefaultPriority::instance())

#endif // ECOSCORE_EVENT_HELPERS_CALLBACK_REGISTRATION_HELPERS_H
