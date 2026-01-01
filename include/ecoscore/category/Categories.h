// File: ecoscore/category/Categories.h
//// File: EcosCore/src/ecoscore/category/Categories.ixx
#ifndef ECOSCORE_ECOSCORE_CATEGORY_CATEGORIES_H
#define ECOSCORE_ECOSCORE_CATEGORY_CATEGORIES_H

#include "std.h"

#include "ecoscore/category/Category.h"
#include "ecoscore/category/Member.h"

#include "ecoscore/category/Flow.h"
#include "ecoscore/category/Outcome.h"
#include "ecoscore/category/Phase.h"

// Export all flow categorys
#include "ecoscore/category/flow/Continue.h"
#include "ecoscore/category/flow/Stop.h"

// Export all phase categorys
#include "ecoscore/category/phase/After.h"
#include "ecoscore/category/phase/Before.h"
#include "ecoscore/category/phase/End.h"
#include "ecoscore/category/phase/Error.h"
#include "ecoscore/category/phase/Finalize.h"
#include "ecoscore/category/phase/Main.h"
#include "ecoscore/category/phase/Process.h"
#include "ecoscore/category/phase/Start.h"

// Export all outcome categorys
#include "ecoscore/category/outcome/Fail.h"
#include "ecoscore/category/outcome/Partial.h"
#include "ecoscore/category/outcome/Pass.h"

namespace ecoscore::category {

    /**
     * @brief Facade category domain struct for module identification.
     */
    struct categoryDomain {
        [[nodiscard]] static constexpr std::string_view name() noexcept {
            return "ecoscore.category";
} // namespace ecoscore::category
    };

}
#endif // ECOSCORE_ECOSCORE_CATEGORY_CATEGORIES_H
