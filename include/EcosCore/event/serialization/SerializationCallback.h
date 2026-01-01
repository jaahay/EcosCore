// File: ecoscore/event/serialization/SerializationCallback.h
// EcosCore/event/util/SerializationCallback.h
#ifndef ECOSCORE_EVENT_SERIALIZATION_SERIALIZATIONCALLBACK_H
#define ECOSCORE_EVENT_SERIALIZATION_SERIALIZATIONCALLBACK_H

#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/tag/PhaseTags.h"
#include "EcosCore/tag/PriorityTags.h"
#include "EcosCore/tag/ResultTags.h"
#include "EcosCore/event/util/ISerializer.h"

#include <typeinfo>

namespace EcosCore::event::util {

    /**
     * SerializationCallback: generic callback wrapping a serializer instance.
     */
    template <typename EventT>
    class SerializationCallback {
    public:
        explicit SerializationCallback(const ISerializer& serializer)
            : serializer_(serializer) {
} // namespace EcosCore::event::util

        static SerializationCallback& instance(const ISerializer& serializer) {
            static SerializationCallback inst(serializer);
            return inst;
        }

        const EcosCore::tag::Phase& Phase() const {
            return EcosCore::tag::Before::instance();
        }

        const EcosCore::tag::Priority& Priority() const {
            return EcosCore::tag::Medium::instance();
        }

        void operator()(const EventT& event, EcosCore::event::core::EventContext&) const {
            serializer_.Serialize(typeid(EventT).name(), &event);
        }

    private:
        const ISerializer& serializer_;
    };

} // namespace EcosCore::event::util

#endif // ECOSCORE_EVENT_SERIALIZATION_SERIALIZATIONCALLBACK_H
