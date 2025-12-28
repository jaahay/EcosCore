// include/ecoscore/EcosCore.h
#ifndef ECOSCORE_ECOSCORE_H
#define ECOSCORE_ECOSCORE_H

/**
 * @file EcosCore.h
 * @brief Umbrella header for the entire EcosCore library.
 *
 * This header includes all primary domain headers, providing a convenient
 * single include point for users of the EcosCore library.
 *
 * Domains included:
 * - meta: Compile-time meta-programming utilities.
 * - type: Type traits, polymorphic base types, and template utilities.
 * - tag: Tagging system with singleton tags and naming.
 * - priority: Priority ordering abstractions and implementations.
 *
 * For finer-grained includes or forward declarations, consider including
 * EcosCoreFwd.h or domain-specific headers directly.
 */

#include "meta/Meta.h"
#include "type/Type.h"
#include "tag/Tag.h"
#include "priority/Priority.h"

#endif // ECOSCORE_ECOSCORE_H
