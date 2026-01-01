// File: ecoscore/integrations/IntegratorTags.h
// include/ecoscore/integration/IntegratorTags.h
#ifndef ECOSCORE_ECOSCORE_INTEGRATIONS_INTEGRATORTAGS_H
#define ECOSCORE_ECOSCORE_INTEGRATIONS_INTEGRATORTAGS_H

/**
 * @file IntegratorTags.h
 * @brief TODO placeholder: base Integrator tag for the integration domain.
 *
 * This file defines the root Integrator tag and concept.
 * Additional integrator categories and concrete tags will be added later.
 *
 * Planned domain and file organization:
 *
 * EcosCore/
 * ├── include/
 * │   ├── ecoscore/
 * │   │   ├── integration/
 * │   │   │   ├── Integrations.h              # Umbrella facade for the integration domain
 * │   │   │   ├── IntegratorTags.h            # Base Integrator tag (this file)
 * │   │   │   ├── DatabaseConnectionTags.h   # Abstract base tag for database connections
 * │   │   │   ├── APIServiceTags.h            # Abstract base tag for API services
 * │   │   │   ├── MessageBrokerTags.h         # Abstract base tag for message brokers
 * │   │   │   ├── IdentityProviderTags.h      # Abstract base tag for identity providers
 * │   │   │   ├── FileStorageTags.h           # Abstract base tag for file storage systems
 * │   │   │   ├── WorkflowEngineTags.h        # Abstract base tag for workflow engines
 * │   │   │   ├── CRMTags.h                   # Abstract base tag for CRM systems
 * │   │   │   ├── Payments.h                   # Abstract base tag for Billing and Payment systems?
 * │   │   │   ├── Concepts.h                   # Concepts for integration tags
 * │   │   │   ├── database/ (db?)              # Concrete database integrators (e.g., MongoDB, OracleDB)
 * │   │   │   ├── api/ (api?)                  # Concrete API integrators (e.g., RESTAPI, GraphQLAPI)
 * │   │   │   ├── message_broker/ (broker?)    # Concrete message brokers (e.g., Kafka, RabbitMQ)
 * │   │   │   ├── identity_provider/ (identity?)# Concrete identity providers (e.g., Okta, Auth0)
 * │   │   │   ├── file_storage/ (file?)         # Concrete file storage integrators (e.g., S3, AzureBlob)
 * │   │   │   ├── workflow_engine/ (???)        # Concrete workflow engines (e.g., Camunda, Zeebe)
 * │   │   │   └── crm/                          # Concrete CRM integrators (e.g., Salesforce, Zendesk)
 *
 * Design notes:
 * - The base `Integrator` tag is the 2-degree root of all integration tags.
 * - Each category tag (e.g., DatabaseConnection, APIService) will inherit from `Integrator`.
 * - Concrete implementations will live under respective subfolders, inheriting from their category tag.
 * - The umbrella `Integrations.h` will include all category headers, exposing the integration domain API.
 * - Concepts will enforce tag category constraints and be placed in `Concepts.h`.
 * - This structure promotes loose coupling, modularity, and extensibility.
 */

#include "ecoscore/tag/TagStruct.h"
#include "ecoscore/concepts/Concepts.h"

namespace ecoscore::integration {

    /**
     * @brief Base tag for all integrators.
     */
    struct Integrator : tag::TagStruct<Integrator> {
    protected:
        constexpr Integrator() noexcept = default;
    };

    /**
     * @brief Concept for integrator tags derived from Integrator.
     */
    template <typename T>
    concept IntegratorTag = std::derived_from<T, Integrator>;

} // namespace ecoscore::integration

#endif // ECOSCORE_ECOSCORE_INTEGRATIONS_INTEGRATORTAGS_H
