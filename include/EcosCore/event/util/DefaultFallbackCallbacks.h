// EcosCore/event/util/DefaultFallbackCallbacks.h
#ifndef ECOSCORE_EVENT_UTIL_DEFAULT_FALLBACK_CALLBACKS_H
#define ECOSCORE_EVENT_UTIL_DEFAULT_FALLBACK_CALLBACKS_H

#include "EcosCore/event/core/EventContext.h"
#include <iostream>

namespace ecoscore::event::util {

    inline void DefaultStopInterceptor(const Event& event, const ecoscore::event::core::EventContext& ctx) {
        std::cerr << "[Fallback] Event dispatch stopped early for event type: "
            << typeid(event).name() << "\n";
    }

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_DEFAULT_FALLBACK_CALLBACKS_H
