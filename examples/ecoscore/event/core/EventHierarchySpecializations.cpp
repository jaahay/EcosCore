// examples/event/core/EventHierarchySpecializations.cpp

#include "EcosCore/event/core/BaseEventList.h"
#include <typeindex>
#include <vector>

struct BaseEvent : ecoscore::event::core::Event {};
struct DerivedEvent : BaseEvent {};

// Specialize BaseEventList for DerivedEvent
template <>
struct ecoscore::event::core::BaseEventList<DerivedEvent> {
	using type = std::tuple<BaseEvent>;
};
