#ifndef XMMWORD_HPP
#define XMMWORD_HPP
#include <cstdint>

namespace gooapi::math {

    struct alignas(16) Txmmword {
        union {
            int8_t mI8[16];
            int16_t mI16[8];
            int32_t mI32[4];
            int64_t mI64[2];
            uint8_t mU8[16];
            uint16_t mU16[8];
            uint32_t mU32[4];
            uint64_t mU64[2];
            float mF32[4];
            double mF64[2];
        };
        
        Txmmword() : Txmmword(0.0f, 0.0f, 0.0f, 0.0f) {}
        Txmmword(float aX, float aY) : Txmmword(aX, aY, 0.0f, 0.0f) {}
        Txmmword(float aX, float aY, float aZ) : Txmmword(aX, aY, aZ, 0.0f) {}
        Txmmword(float aX, float aY, float aZ, float aW) : mF32{aX, aY, aZ, aW} {}

    };

}

using xmmword = gooapi::math::Txmmword;
#endif