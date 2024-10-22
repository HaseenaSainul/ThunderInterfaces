/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2021 Metrological
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
    struct EXTERNAL IDeviceInfo : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_INFO };

        struct FirmwareInfo {
            enum Yocto : uint8_t {
              dunfell,
              morty,
              daisy,
              kirkstone
            };

            string imageName /* @brief Name of firmware image */;
            string sdk /* @brief SDK version string */;
            string mediarite /* @brief Mediarite value */;
            Yocto yocto /* @brief Yocto version */;
        };
        struct DeviceData {
            string deviceType /* @brief Device type */;
            string friendlyName /* @brief Friendly name */;
            string distributorId /* @brief Partner ID or distributor ID for device */;
            string make /* @brief Device manufacturer */;
            string modelName /* @brief Model Name */;
            uint16_t modelYear /* @brief Model Year */;
            string platformName /* @brief Platform name */;
            string serialNumber /* Device serial number */;
            string sku /* Device model number or SKU */;
        };
        struct SystemData {
            struct CPULoadAvgs {
                uint64_t avg1min /* @brief 1min cpuload average */;
                uint64_t avg5min /* @brief 5min cpuload average */;
                uint64_t avg15min /* @brief 15min cpuload average */;
            };
            string version /* @brief Software version (in form *version#hashtag*) */;
            uint64_t uptime /* @brief System uptime (in seconds) */;
            uint64_t totalRAM /* @brief Total installed system RAM memory (in bytes) */;
            uint64_t freeRAM /* @brief Free system RAM memory (in bytes) */;
            uint64_t totalSwap /* @brief Total swap space (in bytes) */;
            uint64_t freeSwap /* @brief Swap space still available (in bytes) */;
            string deviceName /* @brief Host name */;
            string cpuLoad /* @brief Current CPU load (percentage) */;
            CPULoadAvgs cpuLoadAvg /* @brief CPU load average */;
            string serialNumber /* @brief Device serial number */;
            string time /* @brief Current system date and time */;
        };
        struct SocketData {
            uint32_t total /* @brief Number of total */;
            uint32_t open /* @brief Number of open */;
            uint32_t link /* @brief Number of link */;
            uint32_t exception /* @brief Number of exception */;
            uint32_t shutdown /* @brief Number of shutdown */;
            uint32_t runs /* @brief Number of runs */;
        };
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;
        struct AddressData {
            string Name /* @brief Interface name */;
            string Mac /* @brief Interface MAC address */;
            IStringIterator* Ip /* @brief An array of Interface IP address */;
        };

        /* @json:omit */
        virtual uint32_t Configure(const PluginHost::IShell* service) = 0;
        // @property
        // @brief Retrieves Firware Information
        virtual uint32_t FirmwareVersion(FirmwareInfo& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Serial Number
        virtual uint32_t SerialNumber(string& value /* @out */) const = 0;
        // @alt modelid
        // @property
        // @brief Retrieves ModelID/Sku
        virtual uint32_t Sku(string& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Make
        virtual uint32_t Make(string& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Model Name
        virtual uint32_t ModelName(string& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Model Year
        virtual uint32_t ModelYear(uint16_t& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Friendly Name
        virtual uint32_t FriendlyName(string& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Device Type
        virtual uint32_t DeviceType(string& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Platform Name
        virtual uint32_t PlatformName(string& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Distributor Id
        virtual uint32_t DistributorId(string& value /* @out */) const = 0;
        // @property
        // @brief Retrieves DeviceInfo
        virtual uint32_t DeviceInfo(DeviceData& value /* @out */) const = 0;
        // @property
        // @brief Retrieves SystemInfo
        virtual uint32_t SystemInfo(SystemData& value /* @out */) const = 0;
        // @property
        // @brief Retrieves SocketInfo
        virtual uint32_t SocketInfo(SocketData& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Addresses
        virtual uint32_t Addresses(AddressData& value /* @out */) const = 0;
    };

    /* @json 1.0.0 */
    struct EXTERNAL IDeviceAudioCapabilities : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_CAPABILITIES_AUDIO };

        virtual ~IDeviceAudioCapabilities() override = default;

        enum AudioOutput : uint8_t {
            AUDIO_OTHER /* @text: OTHER */,
            AUDIO_RF_MODULATOR /* @text: RF_MODULATOR */,
            AUDIO_ANALOG /* @text: ANALOG */,
            AUDIO_SPDIF /* @text: SPDIF0 */, //over RCA or TOSLINK
            AUDIO_HDMI0 /* @text: HDMI0 */,
            AUDIO_HDMI1 /* @text: HDMI1 */,
            AUDIO_DISPLAYPORT /* @text: DISPLAYPORT */
        };

        enum AudioCapability : uint8_t {
            AUDIOCAPABILITY_NONE /* @text: audiocapability_none */,
            ATMOS /* @text: atmos */,
            DD /* @text: dd */,
            DDPLUS /* @text: ddplus */,
            DAD /* @text: dad */,
            DAPV2 /* @text: dapv2 */,
            MS12 /* @text: ms12 */
        };

        enum MS12Capability : uint8_t {
            MS12CAPABILITY_NONE /* @text: ms12capability_none */,
            DOLBYVOLUME /* @text: dolbyvolume */,
            INTELIGENTEQUALIZER /* @text: inteligentequalizer */,
            DIALOGUEENHANCER /* @text: dialogueenhancer */
        };

        enum MS12Profile : uint8_t {
            MS12PROFILE_NONE /* @text: ms12profile_none */,
            MUSIC /* @text: music */,
            MOVIE /* @text: movie */,
            VOICE /* @text: voice */
        };

        typedef RPC::IIteratorType<AudioOutput, ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT> IAudioOutputIterator;
        typedef RPC::IIteratorType<AudioCapability, ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY> IAudioCapabilityIterator;
        typedef RPC::IIteratorType<MS12Capability, ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY> IMS12CapabilityIterator;
        typedef RPC::IIteratorType<MS12Profile, ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE> IMS12ProfileIterator;

        struct IAudioCapabilities : virtual struct IUnknown {
            // @property
            // @brief Audio Output support
            virtual uint32_t Port(AudioOutput& audioOutput /* @out */) const = 0;
            // @property
            // @brief Retrieves AudioCapabilities
            virtual uint32_t Audio(IAudioCapabilityIterator*& audioCapabilities /* @out */) const = 0;
            // @property
            // @brief Retrieves MS12 Capabilities
            virtual uint32_t MS12(IMS12CapabilityIterator*& ms12Capabilities /* @out */) const = 0;
            // @property
            // @brief Retrieves MS12 Audio Profiles
            virtual uint32_t MS12Profiles(IMS12ProfileIterator*& ms12Profiles /* @out */) const = 0;
        };

        // @alt supportedaudioports
        // @property
        // @brief Retrieves AudioOutputs
        virtual uint32_t AudioOutputs(IAudioOutputIterator*& audioOutputs /* @out */) const = 0;
        // @property
        // @brief Retrieves AudioCapabilities
        virtual uint32_t AudioCapabilities(const AudioOutput audioOutput /* @index */, IAudioCapabilityIterator*& audioCapabilities /* @out */) const = 0;
        // @brief Retrieves MS12 Capabilities
        virtual uint32_t MS12Capabilities(const AudioOutput audioOutput /* @index */, IMS12CapabilityIterator*& ms12Capabilities /* @out */) const = 0;
        // @alt supportedms12audioprofiles
        // @brief Retrieves MS12 Audio Profiles
        virtual uint32_t MS12AudioProfiles(const AudioOutput audioOutput /* @index */, IMS12ProfileIterator*& ms12Profiles /* @out */) const = 0;
        // @brief Retrieves DeviceAudioCapabilities
        virtual IAudioCapabilities* DeviceAudioCapabilities(const AudioOutput audioOutput) = 0;
    };

    /* @json 1.0.0 */
    struct EXTERNAL IDeviceVideoCapabilities : virtual public Core::IUnknown {
        enum { ID = ID_DEVICE_CAPABILITIES_VIDEO };

        virtual ~IDeviceVideoCapabilities() override = default;

        enum VideoOutput : uint8_t {
            VIDEO_OTHER /* @text: OTHER */,
            VIDEO_RF_MODULATOR /* @text: RF_MODULATOR */,
            VIDEO_COMPOSITE /* @text: COMPOSITE */, // also composite over SCART
            VIDEO_SVIDEO /* @text: SVIDEO */,
            VIDEO_COMPONENT /* @text: COMPONENT */,
            VIDEO_SCART_RGB /* @text: SCART_RGB */,
            VIDEO_HDMI0 /* @text: HDMI0 */,
            VIDEO_HDMI1 /* @text:  HDMI1*/,
            VIDEO_DISPLAYPORT /* @text: DISPLAYPORT */ // also DisplayPort over USB-C
        };

        enum ScreenResolution : uint8_t {
            ScreenResolution_Unknown = 0 /* @text: Unknown */,
            ScreenResolution_480i = 1 /* @text: 480i */,
            ScreenResolution_480p = 2 /* @text: 480p */,
            ScreenResolution_576i = 3 /* @text: 576i */,
            ScreenResolution_576p = 4 /* @text: 576p */,
            ScreenResolution_576p50Hz = 5 /* @text: 576p50 */,
            ScreenResolution_720p = 6 /* @text: 720p */,
            ScreenResolution_720p50Hz = 7 /* @text: 720p50 */,
            ScreenResolution_1080i = 8 /* @text: 1080i */,
            ScreenResolution_1080i25Hz = 9 /* @text: 1080i25 */,
            ScreenResolution_1080i50Hz = 10 /* @text: 1080i50 */,
            ScreenResolution_1080p = 11 /* @text: 1080p */,
            ScreenResolution_1080p24Hz = 12 /* @text: 1080p24 */,
            ScreenResolution_1080p25Hz = 13 /* @text: 1080p25 */,
            ScreenResolution_1080p30Hz = 14 /* @text: 1080p30 */,
            ScreenResolution_1080p50Hz = 15 /* @text: 1080p50 */,
            ScreenResolution_1080p60Hz = 16 /* @text: 1080p60 */,
            ScreenResolution_2160p30Hz = 17 /* @text: 2160p30 */,
            ScreenResolution_2160p50Hz = 18 /* @text: 2160p50 */,
            ScreenResolution_2160p60Hz = 19 /* @text: 2160p60 */,
            ScreenResolution_4320p30Hz = 20 /* @text: 4320p30 */,
            ScreenResolution_4320p60Hz = 21 /* @text: 4320p60 */
        };

        enum CopyProtection : uint8_t {
            HDCP_UNAVAILABLE /* @text: unavailable */,
            HDCP_14 /* @text: 1.4 */,
            HDCP_20 /* @text: 2.0 */,
            HDCP_21 /* @text: 2.1 */,
            HDCP_22 /* @text: 2.2 */
        };

        typedef RPC::IIteratorType<VideoOutput, ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT> IVideoOutputIterator;
        typedef RPC::IIteratorType<ScreenResolution, ID_DEVICE_CAPABILITIES_RESOLUTION> IScreenResolutionIterator;

        struct IVideoCapabilities {
            struct IVideoOutputCapabilities {
                // @property
                // @brief Video Output support
                virtual uint32_t Display(VideoOutput& videoOutput /* @out */) const = 0;
                // @property
                // @brief HDCP support
                virtual uint32_t HDCP(CopyProtection& hdcp /* @out */) const = 0;
                // @property
                // @brief  Supported resolutions
                virtual uint32_t Resolutions(IScreenResolutionIterator& screenResolution /* @out */) const = 0;
                // @property
                // @brief Default resolution
                virtual uint32_t DefaultResolution(ScreenResolution& screenResolution /* @out */) const = 0;
            };

            // @property
            // @brief EDID of the host
            virtual uint32_t HostEdid(string& edid /* @out */) const = 0;
            // @property
            // @brief Is HDR supported by this device
            virtual uint32_t HDR(bool& hdr /* @out */) const = 0;
            // @property
            // @brief Is Atmos supported by this device
            virtual uint32_t Atmos(bool& atoms) const = 0;
            // @property
            // @brief Is CEC supported by this device
            virtual uint32_t CEC(bool& cec) const = 0;
            // @property
            // @brief An array of VideoOutputCapabilities
            virtual uint32_t VideoCapabilities(const VideoOutput videoOutput /* @index */, IVideoOutputCapabilities*& videoCapabilities /* @out */) const = 0;
        };

        // @alt supportedvideodisplays
        // @property
        // @brief Retrieves VideoOutputs
        virtual uint32_t VideoOutputs(IVideoOutputIterator*& videoOutputs /* @out */) const = 0;
        // @brief Retrieves DefaultResolution against given video Output
        virtual uint32_t DefaultResolution(const VideoOutput videoOutput /* @index */, ScreenResolution& defaultResolution /* @out */) const = 0;
        // @alt supportedresolutions
        // @brief Retrieves Resolution against given video Output
        virtual uint32_t Resolutions(const VideoOutput videoOutput /* @index */, IScreenResolutionIterator*& resolutions /* @out */) const = 0;
        // @alt supportedhdcp
        // @brief Retrieves Hdcp
        virtual uint32_t Hdcp(const VideoOutput videoOutput /* @index */, CopyProtection& hdcpVersion /* @out */) const = 0;
        // @property
        // @brief Retrieves Host EDID
        virtual uint32_t HostEDID(string& edid /* @out */) const = 0;
        // @brief Retrieves HDR
        virtual uint32_t HDR(bool& supportsHDR /*@out*/) const = 0;
        // @property
        // @brief Retrieves Atoms
        virtual uint32_t Atmos(bool& supportsAtmos /*@out*/) const = 0;
        // @property
        // @brief Retrieves cec
        virtual uint32_t CEC(bool& supportsCEC /*@out*/) const = 0;
        // @brief Retrieves DeviceVideoCapabilities
        virtual IVideoCapabilities* DeviceVideoCapabilities() = 0;
    };
}
}
