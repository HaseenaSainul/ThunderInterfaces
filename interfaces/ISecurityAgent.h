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
    struct EXTERNAL ISecurityAgent : virtual public Core::IUnknown {
        enum { ID = ID_SECURITYAGENT };
        struct TokenParams {
            string url /* @brief Url of application origin */;
            string user /* @brief Username */;
            string hash /* @brief Random hash */;
        };

        // @brief Creates Token
        virtual uint32_t CreateToken(const TokenParams& params, string& token /* @out */) = 0;
        // @brief Validate Token
        virtual uint32_t Validate(const string& token, bool& valid /* @out */) = 0;
    };
}
}
