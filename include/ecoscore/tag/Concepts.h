// include/ecoscore/tag/concepts/Concepts.h
#ifndef ECOSCORE_TAG_CONCEPTS_CONCEPTS_H
#define ECOSCORE_TAG_CONCEPTS_CONCEPTS_H

import ecoscore.EcosCoreFwd;

namespace ecoscore::tag::concepts {

	using ecoscore::concepts::SingletonTag;

	template <typename T>
	concept TagCategory = ecoscore::concepts::TagCategory<T, ecoscore::tag::Tag>;

	template <typename T>
	concept PhaseTag = std::derived_from<T, ecoscore::tag::Phase>;

	template <typename T>
	concept PriorityTag = std::derived_from<T, ecoscore::tag::Priority>;

	template <typename T>
	concept CharsetTag = std::derived_from<T, ecoscore::tag::Charset>;

	template <typename T>
	concept LanguageTag = std::derived_from<T, ecoscore::tag::Language>;

	template <typename T>
	concept ResultTag = std::derived_from<T, ecoscore::tag::ResultFlow> || std::derived_from<T, ecoscore::tag::ResultOutcome>;

} // namespace ecoscore::tag::concepts

#endif // ECOSCORE_TAG_CONCEPTS_CONCEPTS_H
