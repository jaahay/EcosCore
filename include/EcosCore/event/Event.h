// File: ecoscore/event/Event.h
// EcosCore/event/VirtualEvent.h
#ifndef ECOSCORE_ECOSCORE_EVENT_EVENT_H
#define ECOSCORE_ECOSCORE_EVENT_EVENT_H

namespace EcosCore::event {

    /**
     * Base class for all events.
     */
    struct VirtualEvent {
        virtual ~VirtualEvent() = default;
    };

} // namespace EcosCore::event

#endif // ECOSCORE_ECOSCORE_EVENT_EVENT_H
