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

        /* @json:omit */
        virtual Core::hresult Configure(const PluginHost::IShell* service) = 0;
        // @property
        // @brief Retrieves Serial Number
        virtual Core::hresult SerialNumber(string& value /* @out */) const = 0;
        // @alt modelid
        // @property
        // @brief Retrieves ModelID/Sku
        virtual Core::hresult Sku(string& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Make
        virtual Core::hresult Make(string& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Model Name
        virtual Core::hresult ModelName(string& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Model Year
        virtual Core::hresult ModelYear(uint16_t& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Friendly Name
        virtual Core::hresult FriendlyName(string& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Device Type
        virtual Core::hresult DeviceType(string& value /* @out */) const = 0;
        // @property
        // @brief Retrieves Platform Name
        virtual Core::hresult PlatformName(string& value/*@out*/) const = 0;
        // @property
        // @brief Retrieves Distributor Id
        virtual Core::hresult DistributorId(string& value /* @out */) const = 0;
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

        // @alt supportedaudioports
        // @property
        // @brief Retrieves AudioOutputs
        virtual Core::hresult AudioOutputs(IAudioOutputIterator*& audioOutputs /* @out */) const = 0;
        // @property
        // @brief Retrieves AudioCapabilities
        virtual Core::hresult AudioCapabilities(const AudioOutput audioOutput /* @index */, IAudioCapabilityIterator*& audioCapabilities /* @out */) const = 0;
        // @brief Retrieves MS12 Capabilities
        virtual Core::hresult MS12Capabilities(const AudioOutput audioOutput /* @index */, IMS12CapabilityIterator*& ms12Capabilities /* @out */) const = 0;
        // @alt supportedms12audioprofiles
        // @brief Retrieves MS12 Audio Profiles
        virtual Core::hresult MS12AudioProfiles(const AudioOutput audioOutput /* @index */, IMS12ProfileIterator*& ms12Profiles /* @out */) const = 0;
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

        enum ScreenResolution : uint32_t {
            ScreenResolution_Unknown = 0x000000 /* @text: Unknown */,
            ScreenResolution_480i = 0x000001 /* @text: 480i */,
            ScreenResolution_480p = 0x000002 /* @text: 480p */,
            ScreenResolution_576i = 0x000004 /* @text: 576i */,
            ScreenResolution_576p = 0x000008 /* @text: 576p */,
            ScreenResolution_576p50Hz = 0x000010 /* @text: 576p50 */,
            ScreenResolution_720p = 0x000020 /* @text: 720p */,
            ScreenResolution_720p50Hz = 0x000040 /* @text: 720p50 */,
            ScreenResolution_1080i = 0x000080 /* @text: 1080i */,
            ScreenResolution_1080i25Hz = 0x000100 /* @text: 1080i25 */,
            ScreenResolution_1080i50Hz = 0x000200 /* @text: 1080i50 */,
            ScreenResolution_1080p = 0x000400 /* @text: 1080p */,
            ScreenResolution_1080p24Hz = 0x000800 /* @text: 1080p24 */,
            ScreenResolution_1080p25Hz = 0x001000 /* @text: 1080p25 */,
            ScreenResolution_1080p30Hz = 0x002000 /* @text: 1080p30 */,
            ScreenResolution_1080p50Hz = 0x004000 /* @text: 1080p50 */,
            ScreenResolution_1080p60Hz = 0x008000 /* @text: 1080p60 */,
            ScreenResolution_2160p30Hz = 0x010000 /* @text: 2160p30 */,
            ScreenResolution_2160p50Hz = 0x020000 /* @text: 2160p50 */,
            ScreenResolution_2160p60Hz = 0x040000 /* @text: 2160p60 */,
            ScreenResolution_4320p30Hz = 0x080000 /* @text: 4320p30 */,
            ScreenResolution_4320p60Hz = 0x100000 /* @text: 4320p60 */
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


        // @alt supportedvideodisplays
        // @property
        // @brief Retrieves VideoOutputs
        virtual Core::hresult VideoOutputs(IVideoOutputIterator*& videoOutputs /* @out */) const = 0;
        // @brief Retrieves DefaultResolution against given video Output
        virtual Core::hresult DefaultResolution(const VideoOutput videoOutput /* @index */, ScreenResolution& defaultResolution /* @out */) const = 0;
        // @alt supportedresolutions
        // @brief Retrieves Resolution against given video Output
        virtual Core::hresult Resolutions(const VideoOutput videoOutput /* @index */, IScreenResolutionIterator*& resolutions /* @out */) const = 0;
        // @alt supportedhdcp
        // @brief Retrieves Hdcp
        virtual Core::hresult Hdcp(const VideoOutput videoOutput /* @index */, CopyProtection& hdcpVersion /* @out */) const = 0;
        // @property
        // @brief Retrieves Host EDID
        virtual Core::hresult HostEDID(string& edid /* @out */) const = 0;
        // @brief Retrieves HDR
        virtual Core::hresult HDR(bool& supportsHDR /*@out*/) const = 0;
        // @property
        // @brief Retrieves Atoms
        virtual Core::hresult Atmos(bool& supportsAtmos /*@out*/) const = 0;
        // @property
        // @brief Retrieves cec
        virtual Core::hresult CEC(bool& supportsCEC /*@out*/) const = 0;
    };

    namespace JSONRPC {
        // @json 1.0.0
        struct EXTERNAL IDeviceCapabilities {
            virtual ~IDeviceCapabilities() = default;

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
            struct IAddresses : virtual public Core::IUnknown {
                // @brief Interface name
                virtual Core::hresult Name(string& name /* @out */) const = 0;
                // @brief Interface MAC address
                virtual Core::hresult Mac(string& mac /* @out */) const = 0;
                // @brief An array of Interface IP address
                virtual Core::hresult Ip(IStringIterator*& ip /* @out */) const = 0;
            };

            // @property
            // @brief Retrieves Firware Information
            virtual Core::hresult FirmwareVersion(FirmwareInfo& value /* @out */) const = 0;
            // @property
            // @brief Retrieves DeviceInfo
            virtual Core::hresult DeviceInfo(DeviceData& value /* @out */) const = 0;
            // @property
            // @brief Retrieves SystemInfo
            virtual Core::hresult SystemInfo(SystemData& value /* @out */) const = 0;
            // @property
            // @brief Retrieves SocketInfo
            virtual Core::hresult SocketInfo(SocketData& value /* @out */) const = 0;
            // @lookup:Addresses
            // @brief Retrieves Addresses
            virtual IAddresses* Addresses(const uint32_t id) = 0;

            struct IAudioCapabilities : virtual public Core::IUnknown {
                // @property
                // @brief Audio Output support
                virtual Core::hresult Port(IDeviceAudioCapabilities::AudioOutput& audioOutput /* @out */) const = 0;
                // @property
                // @brief Retrieves AudioCapabilities
                virtual Core::hresult Audio(IDeviceAudioCapabilities::IAudioCapabilityIterator*& audioCapabilities /* @out */) const = 0;
                // @property
                // @brief Retrieves MS12 Capabilities
                virtual Core::hresult MS12(IDeviceAudioCapabilities::IMS12CapabilityIterator*& ms12Capabilities /* @out */) const = 0;
                // @property
                // @brief Retrieves MS12 Audio Profiles
                virtual Core::hresult MS12Profiles(IDeviceAudioCapabilities::IMS12ProfileIterator*& ms12Profiles /* @out */) const = 0;
            };
            // @lookup:DeviceAudioCapabilities
            // @brief Retrieves DeviceAudioCapabilities
            virtual IAudioCapabilities* DeviceAudioCapabilities(const IDeviceAudioCapabilities::AudioOutput audioOutput /* @index */) = 0;

            struct VideoOutputCaps {
                IDeviceVideoCapabilities::VideoOutput videoOutput /* @brief Video Output support */;
                IDeviceVideoCapabilities::CopyProtection hdcp /* @brief Video Output support */;
                IDeviceVideoCapabilities::ScreenResolution outputResolutions /* @bitmask @brief Supported resolutions */;
                IDeviceVideoCapabilities::ScreenResolution defaultResolution /* @brief Default resolution */;
            };

            using IVideoOutputCapsIterator = RPC::IIteratorType<VideoOutputCaps, ID_DEVICE_CAPABILITIES_VIDEO_CAPABILITIES>;
            // @brief Retrieves DeviceVideoCapabilities
            virtual Core::hresult DeviceVideoCapabilities(string& edid /* @out */,
                    bool& hdr /* @out */, bool& cec /* @out */,
                    IVideoOutputCapsIterator*& videoOutputCapabilities /* @out */) const = 0;

        };
    } // namespace JSONRPC
}
}
