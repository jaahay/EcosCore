// EcosCore/event/Types.h
#ifndef ECOSCORE_EVENT_TYPES_H
#define ECOSCORE_EVENT_TYPES_H

#include "StrongTypedefs.h"
#include <cstdint>

namespace EcosCore::event {

	/**
	 * Type-safe handle for callbacks.
	 */
	using CallbackHandle = StrongTypedef<uint64_t, struct CallbackHandleTag>;

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_TYPES_H
