```markdown
# EcosCore Category Domain

## Overview

The Category domain defines the core domain tags and concrete members that represent immutable, singleton domain concepts. Categories serve as abstract base tags, while Members are concrete singleton identities within those categories.

## Design Principles

- **Categories** are abstract, non-instantiable tags representing domain concepts.
- **Members** are final, immutable singleton classes that inherit from Categories.
- Singleton instances are lazily initialized, thread-safe, and exposed via static constexpr aliases.
- No runtime polymorphism (no virtual functions) to ensure zero overhead.
- Strong compile-time guarantees via CRTP and static interfaces.
- Private nested wrapper structs encapsulate runtime interface forwarding and are hidden from public API.
- Clear separation between domain identity and implementation details.

## Structure

- `Category.h`: Abstract base tags.
- `Member.h`: CRTP singleton base for concrete members.
- Concrete categories (e.g., `Outcome`, `Flow`, `Phase`).
- Concrete members (e.g., `Pass`, `Fail`, `Continue`, `Start`).

## Usage

```cpp
auto& pass = ecoscore::category::outcome::pass;
std::cout << pass.name() << "\n"; // Outputs "Pass"
```

## Extensibility

Add new domain members by inheriting from `Member<Derived, Category>`, providing a static `name()` and singleton instance.

---

## License

MIT License
```
