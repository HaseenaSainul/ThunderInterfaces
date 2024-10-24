/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#pragma once

#include "Module.h"

// @stubgen:include <com/IIteratorType.h>

namespace Thunder {
namespace Exchange {
    /* @json 1.0.0 */
    struct EXTERNAL IMonitor : virtual public Core::IUnknown {
        enum { ID = ID_MONITOR };
        struct Measurement {
            uint64_t min /* @brief Minimal value measured */;
            uint64_t max /* @brief Maximal value measured */;
            uint64_t average /* @brief Average of all measurements */;
            uint64_t last /* @brief Last measured value */;
        };
        struct Measurements {
            Measurement resident /* @brief Resident memory measurement */;
            Measurement allocated /* @brief Allocated memory measurement */;
            Measurement shared /* @brief Shared memory measurement */;
            Measurement process /* @brief Processes measurement */;
            bool operational /* @brief Whether the service is up and running */;
            uint32_t count /* @brief Number of measurements */;
        };
        struct RestartInfo {
            uint8_t limit /* @brief Maximum number or restarts to be attempted */;
            uint16_t window /* @brief Time period (in seconds) within which failures must happen for the limit to be considered crossed */;
        };
        struct Statistics {
            Measurements measurements /* @brief Measurements for the service */;
            string observable /* @brief A callsign of the watched service */;
            RestartInfo restart /* @brief Restart limits for failures applying to the service */;
        };
        struct ActionParams {
            string callsign /* @brief Callsign of the service the Monitor acted upon */;
            string action /* @brief The action executed by the Monitor on a service. One of: "Activate", "Deactivate", "StoppedRestarting" */;
            string reason /* @brief A message describing the reason the action was taken */;
        };
        struct RestartLimitsParams {
            string callsign /* @brief The callsign of a service to reset measurements snapshot of */;
            RestartInfo restart /* @brief Restart limits for failures applying to the service */;
        };

        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_MONITOR_NOTIFICATION };
            virtual void Action(const string& callsign, const string& action, const string& reason) = 0;
        };

        using IStatisticsIterator = RPC::IIteratorType<Statistics, ID_MONITOR_STATISTICS_ITERATOR>;
        // @brief RestartLimits: Sets new restart limits for a plugin
        virtual uint32_t RestartLimits(const RestartLimitsParams& params) = 0;
        // @brief ResetStats: Resets memory and process statistics for a single plugin watched by the Monitor
        virtual uint32_t ResetStats(const string& callsign, Statistics& statistics /* @out */) = 0;
        // @property
        // @brief Status: The memory and process statistics either for a single plugin or
        // all plugins watched by the Monitor
        virtual uint32_t Status(const string& index /* @index */, IStatisticsIterator*& statistics /* @out */) const = 0;
    };
}
}
