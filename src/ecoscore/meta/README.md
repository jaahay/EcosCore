# EcosCore Meta Domain

## Overview

The **meta** domain in EcosCore provides a collection of **compile-time metaprogramming utilities** designed to empower safe, expressive, and performant type-level programming. Leveraging modern C++20 features such as **modules**, **`constexpr`**, and **concepts**, this domain forms the foundation for complex compile-time algorithms, type transformations, and static assertions critical to EcosCore’s architecture.

---

## Key Features

- **TypeList**: An immutable, variadic compile-time list of types, enabling flexible type manipulation.
- **Cycle Detection (`CheckNoCycle`)**: Compile-time detection of cycles in type dependency graphs to enforce acyclic constraints.
- **Tuple Utilities**: Concatenation and manipulation of `std::tuple` types for advanced type composition.
- **Variant Utilities**: Conversion from tuples to variants and concatenation of multiple variants into a single variant type.
- **Facade Module**: A single import point (`ecoscore.meta.Meta`) that aggregates all meta utilities for ease of use and modularity.

---

## Design Principles

- **Compile-Time Safety**  
  All utilities operate at compile time, using `static_assert` and `constexpr` to guarantee correctness before runtime.

- **Immutability**  
  Types and utilities are designed to be immutable and stateless, supporting functional and declarative programming styles.

- **No Macros or Code Generation**  
  The domain avoids macros and code generation, relying solely on modern C++ language features for clarity and maintainability.

- **Modules-Based Architecture**  
  Implemented entirely as C++20 modules (`.ixx`), improving build performance, encapsulation, and clarity.

- **Tags Paradigm**  
  Where applicable, static-like behavior is exposed via `const` functions or tag structs instead of mutable statics or singletons.

---

## Module Structure

| Module                  | Description                                             |
|-------------------------|---------------------------------------------------------|
| `CycleCheck`            | Compile-time cycle detection in type dependency graphs. |
| `Tuple`                 | Utilities for concatenating and manipulating tuples.    |
| `TypeList`              | Immutable compile-time list of types with manipulation. |
| `Variant`               | Conversion and concatenation utilities for variants.    |
| `Meta` (Facade)         | Aggregates all meta utilities under a single module.    |

---

## Usage Example

```cpp
import ecoscore.meta.Meta;

using namespace ecoscore::meta;

// Define a compile-time type list
using MyTypes = TypeList<int, double, char>;

// Append a type
using ExtendedTypes = Append_t<MyTypes, float>;

// Check for cycles (assuming types define HigherThanList)
static_assert(CheckNoCycle<MyType>::value, "Cycle detected!");

// Concatenate tuples
using Tuple1 = std::tuple<int, double>;
using Tuple2 = std::tuple<char, float>;
using CombinedTuple = tuple_concat_t<Tuple1, Tuple2>;

// Convert tuple to variant
using VariantType = tuple_to_variant_t<CombinedTuple>;
```

---

## Integration

- Ensure your build system supports C++20 modules (EcosCore uses CMake 3.28+).
- Import the facade module `ecoscore.meta.Meta` in your code to access the full meta domain.
- All meta utilities are header-less and modular, minimizing build dependencies and improving compile times.

---

## Contribution Guidelines

- Follow the **immutability** and **compile-time safety** principles.
- Avoid introducing macros or runtime state in the meta domain.
- Use `constexpr` and `static_assert` liberally to enforce correctness.
- Document new utilities with Doxygen-style comments.
- Ensure compatibility with Visual Studio 18 and other major compilers supporting C++20 modules.

---

## License & Credits

EcosCore is developed with a focus on sustainability, integrity, dignity, and compassion. Please refer to the LICENSE file in the root repository for licensing details.

---

*This README is part of the EcosCore project documentation and reflects the current state and philosophy of the meta domain as of 2025.*
