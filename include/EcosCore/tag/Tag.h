// include/ecoscore/tag/Tag.h
#ifndef ECOSCORE_TAG_TAG_H
#define ECOSCORE_TAG_TAG_H

/**
 * @file Tag.h
 * @brief Umbrella header for the tag domain.
 *
 * Includes all primary public headers of the tag module,
 * providing access to tag categories, concrete tags, and concepts.
 */

#include "ecoscore/tag/Category.h"
#include "ecoscore/tag/Flows.h"
#include "ecoscore/tag/Outcomes.h"
#include "ecoscore/tag/Phases.h"
#include "ecoscore/tag/concepts/Concepts.ixx"

 // Include concrete tags as needed or separately
#include "ecoscore/tag/flow/Continue.h"
#include "ecoscore/tag/flow/Stop.h"
#include "ecoscore/tag/outcome/Fail.h"
#include "ecoscore/tag/outcome/Pass.h"
#include "ecoscore/tag/outcome/Partial.h"
#include "ecoscore/tag/phase/After.h"
#include "ecoscore/tag/phase/Before.h"
#include "ecoscore/tag/phase/End.h"
#include "ecoscore/tag/phase/Error.h"
#include "ecoscore/tag/phase/Finalize.h"
#include "ecoscore/tag/phase/Main.h"
#include "ecoscore/tag/phase/Process.h"
#include "ecoscore/tag/phase/Start.h"

#endif  // ECOSCORE_TAG_TAG_H
