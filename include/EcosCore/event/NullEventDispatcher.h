// EcosCore/event/NullEventDispatcher.h
#ifndef ECOSCORE_EVENT_NULL_EVENT_DISPATCHER_H
#define ECOSCORE_EVENT_NULL_EVENT_DISPATCHER_H

#include "EcosCore/event/EventDispatcher.h"

namespace ecoscore::event::null {

    class NullEventDispatcher : public EventDispatcher {
    public:
        static NullEventDispatcher& instance() {
            static NullEventDispatcher inst;
            return inst;
        }

        bool RemoveCallback(CallbackHandle) override {
            // no-op, always return false
            return false;
        }

    private:
        NullEventDispatcher() = default;
        ~NullEventDispatcher() override = default;
    };

} // namespace ecoscore::event::null

#endif // ECOSCORE_EVENT_NULL_EVENT_DISPATCHER_H
