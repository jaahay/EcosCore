# EcosCore Language Domain

## Overview

The Language domain models languages, text representations, charsets, encodings, locales, and translations with strong domain-driven design principles.

## Design Principles

- Language identities are immutable singleton members of the `Language` category.
- Text representations, charsets, and encodings are modeled as categories and concrete members.
- Locales combine language, region, and charset references immutably.
- Translations are modeled as CRTP-based containers with lazy, immutable translation sets.
- Translation containers expose a uniform static `get()` method with fallback handling.
- All domain objects use static singleton patterns with `constexpr` interfaces.
- Private nested wrappers encapsulate implementation details and runtime forwarding.
- No runtime polymorphism or pointers exposed to consumers.

## Structure

- Language identities under `language::lang`.
- Text representations under `language::textrepresentation`.
- Charsets under `language::charset`.
- Encodings under `language::encoding`.
- Translations under `language::translations`.
- Locale aggregates language, region, and charset.

## Usage

```cpp
auto& english = ecoscore::language::lang::en;
auto& locale = ecoscore::language::en_US;
auto& translation = ecoscore::language::translations::en::en;

auto& nameSet = translation.get(english);
```

## Extensibility

Add new languages or translations by defining new singleton members inheriting from appropriate categories or translation containers.

---

## License

MIT License
