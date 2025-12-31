// /src/ecoscore/tag/Detail.ixx
export module ecoscore.tag.detail;

namespace ecoscore::tag::detail {

	// Detect MSVC compiler
#if defined(_MSC_VER)
	export inline constexpr bool is_msvc = true;
#else
	export inline constexpr bool is_msvc = false;
#endif

	// Detect Clang compiler
#if defined(__clang__)
	export inline constexpr bool is_clang = true;
#else
	export inline constexpr bool is_clang = false;
#endif

	// Detect GCC compiler (excluding Clang)
#if defined(__GNUC__) && !defined(__clang__)
	export inline constexpr bool is_gcc = true;
#else
	export inline constexpr bool is_gcc = false;
#endif

} // namespace ecoscore::tag::detail
