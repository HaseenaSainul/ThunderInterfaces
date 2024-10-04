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

namespace Thunder {
namespace Exchange {

    struct EXTERNAL ISecurityPerformance : virtual public Core::IUnknown {

        enum { ID = ID_SECURITY_PERFORMANCE };

        struct IForwarder : public virtual Core::IUnknown {
            enum { ID = ID_SECURITY_PERFORMANCE_FORWARDER };

            virtual Core::hresult Sum (const uint32_t a /* @restrict: 0..10000 */, const uint32_t b /* @restrict: 0..10000 */, uint32_t& sum /* @out */) const = 0;
        };
   
        virtual IForwarder* GetInterface() = 0;

        virtual Core::hresult Sum (const uint32_t a /* @restrict: 0..10000 */, const uint32_t b /* @restrict: 0..10000 */, uint32_t& sum /* @out */) const = 0;
   
        virtual uint32_t Send(const uint16_t sendSize /* @restrict: 8K-1 */, const uint8_t buffer[] /* @length:sendSize @in */ ) = 0;
        virtual uint32_t Receive(uint16_t& bufferSize /* @inout @restrict: 8K-1 */, uint8_t buffer[] /* @length:bufferSize @out */) const = 0;
        virtual uint32_t Exchange(uint16_t& bufferSize /* @inout @restrict: 8K-1 */, uint8_t buffer[] /* @length:bufferSize @maxlength:maxBufferSize @inout*/, const uint16_t maxBufferSize) = 0;
    };
}
}
