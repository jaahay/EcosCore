// File: ecoscore/integrations/Concepts.h
// include/ecoscore/integration/concepts/Concepts.h
#ifndef ECOSCORE_INTEGRATIONS_CONCEPTS_H
#define ECOSCORE_INTEGRATIONS_CONCEPTS_H

/**
 * @file Concepts.h
 * @brief Concepts for the integration domain.
 */

import ecoscore.EcosCoreFwd;

namespace ecoscore::integration::concepts {

	/**
	 * @brief Concept for integrator tags derived from ecoscore::integration::Integrator.
	 */
	template <typename T>
	concept IntegratorTag = std::derived_from<T, ecoscore::integration::Integrator>;

	/**
	 * @brief Concept for database connection integrator tags.
	 */
	template <typename T>
	concept DatabaseConnectionTag = std::derived_from<T, ecoscore::integration::DatabaseConnection>;

	/**
	 * @brief Concept for API service integrator tags.
	 */
	template <typename T>
	concept APIServiceTag = std::derived_from<T, ecoscore::integration::APIService>;

	/**
	 * @brief Concept for message broker integrator tags.
	 */
	template <typename T>
	concept MessageBrokerTag = std::derived_from<T, ecoscore::integration::MessageBroker>;

	/**
	 * @brief Concept for identity provider integrator tags.
	 */
	template <typename T>
	concept IdentityProviderTag = std::derived_from<T, ecoscore::integration::IdentityProvider>;

	/**
	 * @brief Concept for file storage integrator tags.
	 */
	template <typename T>
	concept FileStorageTag = std::derived_from<T, ecoscore::integration::FileStorage>;

	/**
	 * @brief Concept for workflow engine integrator tags.
	 */
	template <typename T>
	concept WorkflowEngineTag = std::derived_from<T, ecoscore::integration::WorkflowEngine>;

	/**
	 * @brief Concept for external service integrator tags.
	 */
	template <typename T>
	concept ExternalServiceTag = std::derived_from<T, ecoscore::integration::ExternalService>;

} // namespace ecoscore::integration::concepts

#endif // ECOSCORE_INTEGRATIONS_CONCEPTS_H
