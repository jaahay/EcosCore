// include/ecoscore/language/Concepts.h
#ifndef ECOSCORE_LANGUAGE_CONCEPTS_H
#define ECOSCORE_LANGUAGE_CONCEPTS_H

/**
 * @file Concepts.h
 * @brief Concepts for the language domain.
 */

import ecoscore.EcosCoreFwd;

namespace ecoscore::language::concepts {

	/**
	 * @brief Concept requiring T to be derived from ecoscore::language::Language.
	 */
	template <typename T>
	concept LanguageTag = std::derived_from<T, ecoscore::language::Language>;

	template <typename T>
	concept CharsetTag = std::derived_from<T, ecoscore::tag::Charset>;

} // namespace ecoscore::language::concepts

#endif // ECOSCORE_LANGUAGE_CONCEPTS_H
