// EcosCore/event/util/SerializationCallback.h
#ifndef ECOSCORE_EVENT_UTIL_SERIALIZATION_CALLBACK_H
#define ECOSCORE_EVENT_UTIL_SERIALIZATION_CALLBACK_H

#include "EcosCore/event/EventCallback.h"
#include "EcosCore/event/CallbackResultState.h"
#include "EcosCore/event/EventContext.h"
#include "EcosCore/state/TemplateState.h"

#include <iostream>
#include <typeinfo>

namespace ecoscore::event::util {

    template <typename EventT>
    class SerializationCallback : public IEventCallback,
        public ecoscore::state::TemplateState<SerializationCallback<EventT>, ecoscore::state::BaseState> {
    private:
        SerializationCallback() = default;

    public:
        static SerializationCallback& instance() {
            static SerializationCallback inst;
            return inst;
        }

        const ecoscore::state::BaseState* Phase() const override {
            return &AfterPhase::instance();
        }

        const ecoscore::state::BaseState* Priority() const override {
            return &DefaultPriority::instance();
        }

        const CallbackResultState& Invoke(const Event& event, EventContext& ctx) const override {
            if (auto derived = dynamic_cast<const EventT*>(&event)) {
                // TODO: Implement actual serialization logic here
                std::cout << "[SERIALIZE] Serializing event: " << typeid(*derived).name() << "\n";
            }
            return Continue::instance();
        }
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_SERIALIZATION_CALLBACK_H
