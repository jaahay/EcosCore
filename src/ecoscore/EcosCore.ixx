// src/ecoscore/Ecoscore.ixx
export module ecoscore;

// Import submodules
export import ecoscore.meta;
export import ecoscore.tag;
export import ecoscore.type;

// Uplift key symbols into ecoscore namespace for ease of use
export namespace ecoscore {
    using meta::TypeList;
    using type::TemplateType;
}
