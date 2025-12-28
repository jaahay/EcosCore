1. Core Domains and Their File Locations
Domain / Feature	Purpose / Description	Suggested File Location & Namespace
Tag Types & Categories	Singleton tags representing phases, priorities, results, charsets, languages, etc.	EcosCore/tag/<br>Namespace: EcosCore::tag
- Base Tag Mixin	Base singleton tag utility	EcosCore/tag/Tag.h
- NameSet (naming metadata)	Rich naming with synonyms, localization, obfuscation	EcosCore/tag/NameSet.h
- Phase Tags	Abstract and concrete phase tags	EcosCore/tag/PhaseTags.h
- Priority Tags	Abstract and concrete priority tags	EcosCore/tag/PriorityTags.h
- Result Tags	Abstract and concrete callback result tags	EcosCore/tag/ResultTags.h
- Charset Tags	Charset category and concrete tags	EcosCore/tag/CharsetTags.h
- Language Tags	Language category and concrete tags	EcosCore/tag/LanguageTags.h
- Priority Ordering Classes	Priority ordering logic (graph, base, template)	EcosCore/tag/PriorityOrdering.h<br>PriorityOrderingGraph.h<br>PriorityOrderingBase.h
- Tag Concepts	Concepts related to tags	EcosCore/tag/concepts/Concepts.h
Domain / Feature	Purpose / Description	Suggested File Location & Namespace
Type Utilities	Base types and CRTP templates	EcosCore/type/<br>Namespace: EcosCore::type
- Base Struct Type	Base polymorphic struct	EcosCore/type/StructType.h
- Template Type CRTP	CRTP base template for type hierarchies	EcosCore/type/TemplateType.h
- Type Concepts	Concepts for type traits and constraints	EcosCore/type/concepts/Concepts.h
Domain / Feature	Purpose / Description	Suggested File Location & Namespace
Event Core System	Event dispatching, callback management, event context, hierarchies, fallback callbacks	EcosCore/event/core/<br>Namespace: EcosCore::event::core
- EventDispatcher	Central event dispatcher	EcosCore/event/core/EventDispatcher.h
- CallbackManager	Manages callbacks per event type, phase, priority	EcosCore/event/core/CallbackManager.h
- CallbackHandle	Strong typedef for callback handles	EcosCore/event/core/CallbackHandle.h
- EventCallback	Template callback wrapper	EcosCore/event/core/EventCallback.h
- EventContext	Event invocation context with cancellation, user data	EcosCore/event/core/EventContext.h
- EventHierarchy*	Event hierarchy classes and caches	EcosCore/event/core/EventHierarchy.h and related files
- FallbackCallbacks	Internal fallback callbacks	EcosCore/event/core/InternalFallbackCallbacks.h
- PhaseInvoker	Invokes callbacks for a given phase	EcosCore/event/core/PhaseInvoker.h
- IEventCallback	Abstract callback interface	EcosCore/event/core/VirtualEventCallback.h (renamed)
- ICallbackManager	Abstract callback manager interface	EcosCore/event/core/VirtualCallbackManager.h (renamed)
- NullEventDispatcher	No-op dispatcher singleton	EcosCore/event/core/NullEventDispatcher.h
- CallbackRegistration Helpers	Helpers for callback registration	EcosCore/event/helpers/CallbackRegistrationHelpers.h
- EventHierarchy Helpers	Helpers for event hierarchy management	EcosCore/event/core/EventHierarchyHelpers.h
Domain / Feature	Purpose / Description	Suggested File Location & Namespace
Utility Implementations	Default concrete implementations of logging, metrics, serialization, timing	EcosCore/event/util/logger/<br>metrics/<br>serialization/<br>timing/<br>Namespaces: EcosCore::event::logger, etc.
- Virtual Interfaces	Abstract interfaces for utilities	EcosCore/event/util/logger/VirtualLogger.h and similar
- Default Implementations	Concrete classes like DebugLogger, ConsoleMetricsReporter	EcosCore/event/util/logger/DebugLogger.h, etc.
- Utility Callbacks	Wrappers adapting utilities to callbacks	EcosCore/event/util/LoggingCallback.h, etc.
- DefaultFallbackCallbacks	User-visible fallback callbacks	EcosCore/event/util/DefaultFallbackCallbacks.h
Domain / Feature	Purpose / Description	Suggested File Location & Namespace
Examples	Integration and usage examples	EcosCore/examples/ with subfolders by utility type
