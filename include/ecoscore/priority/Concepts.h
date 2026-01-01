// File: ecoscore/priority/Concepts.h
// include/ecoscore/tag/concepts/Concepts.h
#ifndef ECOSCORE_ECOSCORE_PRIORITY_CONCEPTS_H
#define ECOSCORE_ECOSCORE_PRIORITY_CONCEPTS_H

import ecoscore.Concepts;

namespace ecoscore::tag::concepts {

	/**
	 * @brief Reuse SingletonTag from ecoscore::concepts.
	 */
	using ecoscore::concepts::SingletonTag;

	/**
	 * @brief Concept for tag categories in tag domain.
	 */
	template <typename T>
	concept TagCategory = ecoscore::concepts::TagCategory<T, ecoscore::tag::Tag>;

	/**
	 * @brief Concept for priority tags.
	 */
	template <typename T>
	concept PriorityTag = std::derived_from<T, ecoscore::tag::Priority>;

} // namespace ecoscore::tag::concepts

#endif // ECOSCORE_ECOSCORE_PRIORITY_CONCEPTS_H
