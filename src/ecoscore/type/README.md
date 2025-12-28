# EcosCore Type Module

This module defines core type abstractions and concepts forming the backbone of the EcosCore type system.

## Key Components

- **StructType**: Abstract base struct for polymorphic hierarchies with runtime printing support.
- **TemplateType**: CRTP base template providing compile-time type identity and runtime printing.
- **Concepts**: C++20 concepts constraining types within the type domain, including:
  - `DerivedFromStructType`
  - `ConcreteType`
  - `SingletonTag`
  - `TagCategory`

## Usage

Import the C++20 module:

```cpp
import ecoscore.type;
```

Or include the umbrella forward declaration header:

```cpp
#include "ecoscore/Type.h"
```

Use these abstractions and concepts to define and constrain your types consistently and safely.

## Build

This module is built as part of the EcosCore modular build system using C++20 modules. See the top-level `CMakeLists.txt` for build instructions.

---

© EcosCore Project
