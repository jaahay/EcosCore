# EcosCore Tag Domain

## Overview

The **tag** domain in EcosCore provides a robust, immutable, and compile-time safe system of **tag categories and concrete tags** used for compile-time dispatch, serialization keys, metadata identification, and flow control.

Implemented entirely as **C++20 modules**, this domain leverages CRTP and singleton-like patterns to provide zero-overhead, stateless tag types that form the backbone of EcosCore’s event, priority, and workflow systems.

---

## Key Features

- **Category Base**: A CRTP base template providing singleton instance and canonical `static_name()` for all tag categories.
- **Flow Tags**: Tags controlling flow logic, e.g., `Continue`, `Stop`.
- **Phase Tags**: Tags representing phases in processing pipelines, e.g., `Start`, `Process`, `Finalize`.
- **Outcome Tags**: Tags representing results or outcomes, e.g., `Pass`, `Fail`, `Partial`.
- **Immutable and Final**: Concrete tags are immutable, final types ensuring thread safety and correctness.
- **Tag Paradigm**: Uses `constexpr` static functions and singleton patterns to avoid mutable globals or statics.
- **Modular Architecture**: All tags are provided as modular interfaces (`.ixx`), improving build times and encapsulation.

---

## Module Structure

| Module/Submodule             | Description                                    |
|-----------------------------|------------------------------------------------|
| `Category`                  | Base CRTP template for all tag categories.     |
| `Flows`                    | Abstract flow control tag base.                  |
| `Outcomes`                 | Abstract outcome tag base.                       |
| `Phases`                   | Abstract phase tag base.                         |
| `flow/Continue`, `flow/Stop` | Concrete flow tags.                             |
| `phase/*`                  | Concrete phase tags (`After`, `Before`, etc.). |
| `outcome/*`                | Concrete outcome tags (`Pass`, `Fail`, etc.).  |
| `Tag` (facade)             | Facade module exporting all tag modules.       |

---

## Usage Example

```cpp
import ecoscore.tag.Tag;

using namespace ecoscore::tag;

// Obtain singleton instances
constexpr auto& continueTag = flow::Continue::instance();
constexpr auto& startPhase = phase::Start::instance();
constexpr auto& passOutcome = outcome::Pass::instance();

// Access canonical internal names
static_assert(continueTag.static_name() == "Continue");
static_assert(startPhase.static_name() == "Start");
static_assert(passOutcome.static_name() == "Pass");
```

---

## Integration

- Import the facade module `ecoscore.tag.Tag` to access the entire tag domain.
- Use the singleton `instance()` method to get immutable tag instances.
- Use `static_name()` for stable, canonical string keys in compile-time dispatch or serialization.
- All tag types are `final` and immutable to ensure thread safety and correctness.

---

## Contribution Guidelines

- Maintain immutability and avoid runtime state.
- Use CRTP and singleton patterns as established.
- Provide clear, canonical `static_name()` strings.
- Document new tags with Doxygen-style comments.
- Follow C++20 module conventions and project-wide compile-time safety standards.

---

## License & Credits

EcosCore is developed with a focus on sustainability, integrity, dignity, and compassion. Please see the LICENSE file in the root repository for details.

---

*This README reflects the current design and philosophy of the EcosCore tag domain as of 2025.*
