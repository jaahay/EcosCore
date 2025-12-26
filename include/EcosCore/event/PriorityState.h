// EcosCore/event/PriorityState.h
#ifndef ECOSCORE_EVENT_PRIORITY_STATE_H
#define ECOSCORE_EVENT_PRIORITY_STATE_H

#include "EcosCore/state/BaseState.h"

namespace ecoscore::event {

    // Marker base class for priority states
    struct PriorityState : ecoscore::state::BaseState {
        virtual ~PriorityState() = default;
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_PRIORITY_STATE_H
