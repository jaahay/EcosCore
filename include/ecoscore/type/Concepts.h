// include/ecoscore/type/concepts/Concepts.h
#ifndef ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H
#define ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H

import ecoscore.EcosCoreFwd;

namespace ecoscore::type::concepts {

	/**
	 * @brief Concept requiring T to be a tag category derived from ecoscore::type::StructType.
	 */
	template <typename T>
	concept TagCategory = ecoscore::concepts::TagCategory<T, ecoscore::type::StructType>;

	// Note: SingletonTag concept is not used in this domain and can be removed or added if needed in future.
	// using ecoscore::concepts::SingletonTag;

} // namespace ecoscore::type::concepts

#endif // ECOSCORE_TYPE_CONCEPTS_CONCEPTS_H
