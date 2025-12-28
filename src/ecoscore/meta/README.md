# EcosCore Meta Module

This module provides foundational compile-time utilities and metaprogramming constructs used throughout the EcosCore framework.

## Key Components

- **TypeList**: A compile-time list of types supporting operations like containment checking and appending.
- **CycleCheck**: Compile-time detection of cycles in type dependency graphs to ensure acyclic priority or dependency orderings.
- **Tuple Utilities**: Facilities to concatenate and manipulate `std::tuple` types at compile-time.
- **Variant Utilities**: Tools to convert tuples to variants and concatenate multiple variants.

## Usage

Import the C++20 module:

```cpp
import ecoscore.meta;
```

Or include the umbrella forward declaration header:

```cpp
#include "ecoscore/Meta.h"
```

Use the utilities in your compile-time code for safer and more expressive metaprogramming.

## Build

This module is built as part of the EcosCore modular build system using C++20 modules. See the top-level `CMakeLists.txt` for build instructions.

---

© EcosCore Project
