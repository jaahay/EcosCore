// EcosCore/event/util/serialization/VirtualSerializer.h
#ifndef ECOSCORE_EVENT_UTIL_SERIALIZATION_VIRTUALSERIALIZER_H
#define ECOSCORE_EVENT_UTIL_SERIALIZATION_VIRTUALSERIALIZER_H

#include <string_view>

namespace EcosCore::event::util::serialization {

    /**
     * VirtualSerializer: abstract serializer interface.
     */
    class VirtualSerializer {
    public:
        virtual ~VirtualSerializer() = default;
        virtual void Serialize(std::string_view eventTypeName, const void* eventData) const = 0;
    };

} // namespace EcosCore::event::util::serialization

#endif // ECOSCORE_EVENT_UTIL_SERIALIZATION_VIRTUALSERIALIZER_H
