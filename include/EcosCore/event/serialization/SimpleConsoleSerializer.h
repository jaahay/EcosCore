// File: ecoscore/event/serialization/SimpleConsoleSerializer.h
// EcosCore/event/util/serialization/SimpleConsoleSerializer.h
#ifndef ECOSCORE_ECOSCORE_EVENT_SERIALIZATION_SIMPLECONSOLESERIALIZER_H
#define ECOSCORE_ECOSCORE_EVENT_SERIALIZATION_SIMPLECONSOLESERIALIZER_H

#include "VirtualSerializer.h"
#include "EcosCore/event/Event.h"
#include <iostream>
#include <string_view>
#include <typeinfo>

namespace EcosCore::event::util::serialization {

    /**
     * SimpleConsoleSerializer:
     * Prints event type name and attempts to print event data if operator<< is defined.
     */
    class SimpleConsoleSerializer : public VirtualSerializer {
    public:
        void Serialize(std::string_view eventTypeName, const void* eventData) const override {
            if (eventData == nullptr) {
                std::cout << "{ \"event_type\": \"" << eventTypeName << "\", \"data\": null }\n";
                return;
} // namespace EcosCore::event::util::serialization

            // Attempt to cast to Event base class and print type name (safe fallback)
            const EcosCore::event::Event* baseEvent = static_cast<const EcosCore::event::Event*>(eventData);
            if (baseEvent) {
                std::cout << "{ \"event_type\": \"" << eventTypeName << "\" }\n";
            }
            else {
                std::cout << "{ \"event_type\": \"" << eventTypeName << "\", \"data\": \"unserializable\" }\n";
            }
        }
    };

} // namespace EcosCore::event::util::serialization

#endif // ECOSCORE_ECOSCORE_EVENT_SERIALIZATION_SIMPLECONSOLESERIALIZER_H
