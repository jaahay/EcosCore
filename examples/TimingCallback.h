// EcosCore/event/util/TimingCallback.h
#ifndef ECOSCORE_EVENT_UTIL_TIMING_CALLBACK_H
#define ECOSCORE_EVENT_UTIL_TIMING_CALLBACK_H

#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/tag/ResultTags.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"
#include "EcosCore/event/util/ITimer.h"

#include <typeinfo>

namespace EcosCore::event::util {

    /**
     * TimingCallback: generic callback wrapping a timer.
     */
    template <typename EventT>
    class TimingCallback {
    public:
        explicit TimingCallback(ITimer& timer)
            : timer_(timer) {
        }

        static TimingCallback& instance(ITimer& timer) {
            static TimingCallback inst(timer);
            return inst;
        }

        const EcosCore::tag::Phase& Phase() const {
            return EcosCore::tag::Before::instance();
        }

        const EcosCore::tag::Priority& Priority() const {
            return EcosCore::tag::Medium::instance();
        }

        void operator()(const EventT& event, EcosCore::event::core::EventContext&) const {
            timer_.Start();
            // User code or next callback invocation should happen here
            timer_.Stop();
            // Log or expose elapsed time as needed
        }

    private:
        ITimer& timer_;
    };

} // namespace EcosCore::event::util

#endif // ECOSCORE_EVENT_UTIL_TIMING_CALLBACK_H
