// File: ecoscore/event/timing/VirtualTimer.h
// EcosCore/event/util/timing/VirtualTimer.h
#ifndef ECOSCORE_ECOSCORE_EVENT_TIMING_VIRTUALTIMER_H
#define ECOSCORE_ECOSCORE_EVENT_TIMING_VIRTUALTIMER_H

namespace EcosCore::event::util::timing {

    /**
     * VirtualTimer: abstract timer interface.
     */
    class VirtualTimer {
    public:
        virtual ~VirtualTimer() = default;
        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual double ElapsedMilliseconds() const = 0;
        virtual void LogElapsed(std::string_view eventTypeName) const = 0;
    };

} // namespace EcosCore::event::util::timing

#endif // ECOSCORE_ECOSCORE_EVENT_TIMING_VIRTUALTIMER_H
