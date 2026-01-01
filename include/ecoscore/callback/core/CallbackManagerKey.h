// File: ecoscore/callback/core/CallbackManagerKey.h
// EcosCore/event/core/CallbackManagerKey.h
#ifndef ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKMANAGERKEY_H
#define ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKMANAGERKEY_H

#include <functional>
#include <string_view>
#include "EcosCore/state/Identified.h"

namespace EcosCore::event::core {

    /**
     * @brief Key for CallbackManager storage in EventDispatcher.
     * Uses references to Identified singletons for event type, phase, and priority.
     */
    struct CallbackManagerKey {
        const EcosCore::state::Identified<void>& event_id;
        const EcosCore::state::Identified<void>& phase_id;
        const EcosCore::state::Identified<void>& priority_id;

        CallbackManagerKey(
            const EcosCore::state::Identified<void>& e,
            const EcosCore::state::Identified<void>& p,
            const EcosCore::state::Identified<void>& pr)
            : event_id(e), phase_id(p), priority_id(pr) {
} // namespace EcosCore::event::core

        bool operator==(const CallbackManagerKey& other) const noexcept {
            return &event_id == &other.event_id
                && &phase_id == &other.phase_id
                && &priority_id == &other.priority_id;
        }
    };

} // namespace EcosCore::event::core

namespace std {
    template <>
    struct hash<EcosCore::event::core::CallbackManagerKey> {
        size_t operator()(const EcosCore::event::core::CallbackManagerKey& key) const noexcept {
            auto h1 = std::hash<const void*>{}(std::addressof(key.event_id));
            auto h2 = std::hash<const void*>{}(std::addressof(key.phase_id));
            auto h3 = std::hash<const void*>{}(std::addressof(key.priority_id));
            return h1 ^ (h2 << 1) ^ (h3 << 2);
} // namespace std
    };
}

#endif // ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKMANAGERKEY_H
