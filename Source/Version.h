#pragma once

struct VersionVariantFlagBits 
{
    enum Flags
    {
        Debug = 0x00000001,
        Prototype = 0x00000002,
        Indev = 0x00000004,
        Alpha = 0x00000008,
        Beta = 0x00000010,
        Prerelease = 0x00000020,
        Release = 0x00000040,
        Snapshot = 0x00000080
    };
};

#define MAGINVOX_DEBUG 1
#define MAGINVOX_VERSION_MAJOR 0
#define MAGINVOX_VERSION_MINOR 1
#define MAGINVOX_VERSION_PATCH 0
#define MAGINVOX_VERSION_VARIANT VersionVariantFlagBits::Debug | VersionVariantFlagBits::Prototype