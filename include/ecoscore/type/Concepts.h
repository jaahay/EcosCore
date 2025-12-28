// include/ecoscore/type/concepts/Concepts.h
#ifndef ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H
#define ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H

import ecoscore.EcosCoreFwd;

namespace ecoscore::type::concepts {

	using ecoscore::concepts::SingletonTag;

	template <typename T>
	concept TagCategory = ecoscore::concepts::TagCategory<T, ecoscore::type::StructType>;

} // namespace ecoscore::type::concepts

#endif // ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H
