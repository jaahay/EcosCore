// EcosCore/state/PriorityState.h
#ifndef ECOSCORE_STATE_PRIORITY_STATE_H
#define ECOSCORE_STATE_PRIORITY_STATE_H

#include "EcosCore/state/BaseState.h"

namespace ecoscore::state {

    // Marker base class for priority states
    struct PriorityState : ecoscore::state::BaseState {
        virtual ~PriorityState() = default;
    };

} // namespace ecoscore::state

#endif // ECOSCORE_STATE_PRIORITY_STATE_H
