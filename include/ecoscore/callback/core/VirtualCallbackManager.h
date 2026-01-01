// File: ecoscore/callback/core/VirtualCallbackManager.h
// EcosCore/event/core/VirtualCallbackManager.h
#ifndef ECOSCORE_CALLBACK_CORE_VIRTUALCALLBACKMANAGER_H
#define ECOSCORE_CALLBACK_CORE_VIRTUALCALLBACKMANAGER_H

#include "EcosCore/event/core/CallbackHandle.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/event/Event.h"

namespace EcosCore::event::core {

    /**
     * VirtualCallbackManager: abstract interface for callback managers.
     */
    class VirtualCallbackManager {
    public:
        virtual ~VirtualCallbackManager() = default;

        virtual void RemoveCallback(CallbackHandle handle) = 0;

        virtual void Dispatch(const Event& event, EventContext& ctx) = 0;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_CALLBACK_CORE_VIRTUALCALLBACKMANAGER_H
