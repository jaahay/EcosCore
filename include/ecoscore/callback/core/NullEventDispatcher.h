// File: ecoscore/callback/core/NullEventDispatcher.h
// EcosCore/event/core/NullEventDispatcher.h
#ifndef ECOSCORE_CALLBACK_CORE_NULLEVENTDISPATCHER_H
#define ECOSCORE_CALLBACK_CORE_NULLEVENTDISPATCHER_H

#include "EcosCore/event/core/CallbackHandle.h"

namespace EcosCore::event::core {

    /**
     * NullEventDispatcher:
     * A singleton dispatcher that performs no operations.
     * Useful as a safe default or placeholder.
     */
    class NullEventDispatcher {
    public:
        static NullEventDispatcher& instance() {
            static NullEventDispatcher inst;
            return inst;
} // namespace EcosCore::event::core

        CallbackHandle AddCallback(...) {
            return CallbackHandle{};
        }

        void RemoveCallback(CallbackHandle) {}

        template <typename EventType, typename PhaseTag>
        void Dispatch(const EventType&, const PhaseTag&) {}

    private:
        NullEventDispatcher() = default;
        NullEventDispatcher(const NullEventDispatcher&) = delete;
        NullEventDispatcher& operator=(const NullEventDispatcher&) = delete;
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_CALLBACK_CORE_NULLEVENTDISPATCHER_H
