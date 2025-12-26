// EcosCore/state/PriorityState.h
#ifndef ECOSCORE_STATE_PRIORITY_STATE_H
#define ECOSCORE_STATE_PRIORITY_STATE_H

#include "EcosCore/state/BaseState.h"

namespace ecoscore::event {

    // Marker base class for priority states
    struct PriorityState : ecoscore::state::BaseState {
        virtual ~PriorityState() = default;
    };

} // namespace ecoscore::event

#endif // ECOSCORE_STATE_PRIORITY_STATE_H
