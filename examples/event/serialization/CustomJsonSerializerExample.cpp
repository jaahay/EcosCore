// examples/event/serialization/CustomJsonSerializerExample.cpp

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/util/SerializationCallback.h"
#include "EcosCore/event/util/ISerializer.h"
#include "EcosCore/event/Event.h"
#include <iostream>
#include <nlohmann/json.hpp>  // Using nlohmann::json for example

using json = nlohmann::json;

class JsonSerializer : public EcosCore::event::util::ISerializer {
public:
    void Serialize(std::string_view eventTypeName, const void* eventData) const override {
        // For demonstration, assume eventData points to a struct with to_json method
        if (eventData == nullptr) {
            std::cout << "{}\n";
            return;
        }
        // Cast and serialize
        // For simplicity, just output event type name here
        json j;
        j["event_type"] = eventTypeName;
        std::cout << j.dump() << std::endl;
    }
};

struct MyEvent : EcosCore::event::Event {
    int id = 42;
};

int main() {
    EcosCore::event::core::EventDispatcher dispatcher;

    JsonSerializer serializer;

    // Register serialization callback for MyEvent
    dispatcher.AddCallback<MyEvent>(
        EcosCore::event::util::SerializationCallback<MyEvent>::instance(serializer),
        EcosCore::tag::Before::instance(),
        EcosCore::tag::Medium::instance());

    MyEvent event;
    dispatcher.Dispatch(event, EcosCore::tag::Before::instance());

    return 0;
}
