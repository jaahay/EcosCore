// src/ecoscore/type/Concepts.ixx
export module ecoscore.type.Concepts;

import <type_traits>;
import <concepts>;
import ecoscore.type.StructType;

export namespace ecoscore::type::concepts {

	/**
	 * @brief Concept requiring T to be derived from StructType.
	 */
	template <typename T>
	concept DerivedFromStructType = std::is_base_of_v<ecoscore::type::StructType, T>;

	/**
	 * @brief Concept requiring T to be a concrete (non-abstract) StructType.
	 */
	template <typename T>
	concept ConcreteType = DerivedFromStructType<T> && !std::is_abstract_v<T>;

} // namespace ecoscore::type::concepts
