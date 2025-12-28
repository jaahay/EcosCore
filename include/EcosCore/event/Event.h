// EcosCore/event/VirtualEvent.h
#ifndef ECOSCORE_EVENT_VIRTUAL_EVENT_H
#define ECOSCORE_EVENT_VIRTUAL_EVENT_H

namespace EcosCore::event {

    /**
     * Base class for all events.
     */
    struct VirtualEvent {
        virtual ~VirtualEvent() = default;
    };

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_VIRTUAL_EVENT_H