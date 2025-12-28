// src/ecoscore/tag/LocalizedName.ixx
module ecoscore.tag.LocalizedName;

export namespace ecoscore::tag {

    /**
     * @brief Represents a localized name with optional charset information.
     */
    struct LocalizedName {
        std::string_view name;
        std::string_view charset; ///< e.g., "UTF-8"

        constexpr LocalizedName(std::string_view n = "", std::string_view cs = "UTF-8") noexcept
            : name(n), charset(cs) {
        }
    };

} // namespace ecoscore::tag
