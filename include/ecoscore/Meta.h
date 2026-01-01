// File: ecoscore/Meta.h
#ifndef ECOSCORE_ECOSCORE_META_H
#define ECOSCORE_ECOSCORE_META_H
// src/ecoscore/Meta.ixx
module ecoscore.meta;

#include "ecoscore/meta/CycleCheck.h"
#include "ecoscore/meta/Tuple.h"
#include "ecoscore/meta/TypeList.h"
#include "ecoscore/meta/Variant.h"

namespace ecoscore::meta {
    using CheckNoCycle = CheckNoCycle;
    using tuple_concat = tuple_concat;
    using tuple_concat_t = tuple_concat_t;
    using tuple_concat_many = tuple_concat_many;
    using tuple_concat_many_t = tuple_concat_many_t;
    using TypeList = TypeList;
    using Contains = Contains;
    using Append = Append;
    using tuple_to_variant = tuple_to_variant;
    using tuple_to_variant_t = tuple_to_variant_t;
    using variant_concat = variant_concat;
    using variant_concat_t = variant_concat_t;
} // namespace ecoscore::meta
#endif // ECOSCORE_ECOSCORE_META_H
