// EcosCore/event/core/VirtualCallbackManager.h
#ifndef ECOSCORE_EVENT_CORE_VIRTUAL_CALLBACK_MANAGER_H
#define ECOSCORE_EVENT_CORE_VIRTUAL_CALLBACK_MANAGER_H

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

#endif // ECOSCORE_EVENT_CORE_VIRTUAL_CALLBACK_MANAGER_H
