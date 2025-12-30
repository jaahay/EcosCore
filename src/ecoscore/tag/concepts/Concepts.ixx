// include/ecoscore/tag/concepts/Concepts.ixx
export module ecoscore.tag.concepts;

import <type_traits>;
import <string_view>;
import <concepts>;

export namespace ecoscore::tag::concepts {

    template <typename T>
    concept Tag = requires {
        typename T::DerivedType;
        requires std::is_final_v<T>;
        requires std::is_default_constructible_v<T> == false;
        { T::static_name() } -> std::convertible_to<std::string_view>;
        { T::instance() } -> std::same_as<const T&>;
    };

    template <typename T, template<typename> typename Category>
    concept Category = Tag<T> && std::derived_from<T, Category<T>>;

    template <typename T>
    concept Concrete = Tag<T> && (!std::is_abstract_v<T>);

    template <typename T>
    concept FlowTag = TagCategory<T, ecoscore::tag::Flow>;

    template <typename T>
    concept OutcomeTag = TagCategory<T, ecoscore::tag::Outcome>;

    template <typename T>
    concept PhaseTag = TagCategory<T, ecoscore::tag::Phase>;

}
