// File: ecoscore/category/Category.h
#ifndef ECOSCORE_CATEGORY_CATEGORY_H_
#define ECOSCORE_CATEGORY_CATEGORY_H_

#include <string_view>

namespace ecoscore::category {

    /**
     * @brief Abstract base tag for all categories.
     *
     * Non-instantiable and immutable.
     */
    struct Category {
    protected:
        constexpr Category() noexcept
            : wrapper_(Wrapper::instance())
        {
        }

    public:
        Category(const Category&) = delete;
        Category& operator=(const Category&) = delete;
        ~Category() noexcept = default;

        std::string_view name() const noexcept {
            return wrapper_.name();
        }

    private:
        struct Wrapper final {
            static const Wrapper& instance() {
                static const Wrapper inst{};
                return inst;
            }

            std::string_view name() const noexcept {
                return Category::name();
            }
        };

        const Wrapper& wrapper_;
    };

} // namespace ecoscore::category

#endif // ECOSCORE_CATEGORY_CATEGORY_H_
