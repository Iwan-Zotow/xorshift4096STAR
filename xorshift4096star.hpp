// -*- C++ -*-

#pragma once

#include <cstdint>
#include <algorithm>
#include <limits>

namespace OTI
{
    class xorshift4096star
    {
#pragma region Typedefs/Constants
        public: using result_type = unsigned long long;
        public: using seed_type   = unsigned long long;

        // those values are from S.Vigna "An experimental exploration of Marsaglia's xorshift generators, scrambled",
        // http://arxiv.org/abs/1402.6246, known as M(31,11,30) with scrambling
        public: static constexpr uint32_t shift_a = 25U;
        public: static constexpr uint32_t shift_b =  3U;
        public: static constexpr uint32_t shift_c = 49U;

        public: static constexpr result_type  mult  = 8372773778140471301ULL;

        public: static const     seed_type    default_seed[];

        public: static constexpr float        norm  = float{double{1.0}/double(std::numeric_limits<result_type>::max())}; // narrowing conversion
#pragma endregion

#pragma region Data
        private: mutable seed_type _seed[64];
        private: mutable int       _p;
#pragma endregion

#pragma region Ctor/Dtor/op=
        public: xorshift4096star(const seed_type* seed = default_seed):
            _seed{seed[ 0], seed[ 1], seed[ 2], seed[ 3], seed[ 4], seed[ 5], seed[ 6], seed[ 7], seed[ 8], seed[ 9], seed[10], seed[11], seed[12], seed[13], seed[14], seed[15],
                  seed[16], seed[17], seed[18], seed[19], seed[20], seed[21], seed[22], seed[23], seed[24], seed[25], seed[26], seed[27], seed[28], seed[29], seed[30], seed[31],
                  seed[32], seed[33], seed[34], seed[35], seed[36], seed[37], seed[38], seed[39], seed[40], seed[41], seed[42], seed[43], seed[44], seed[45], seed[46], seed[47],
                  seed[48], seed[49], seed[50], seed[51], seed[52], seed[53], seed[54], seed[55], seed[56], seed[57], seed[58], seed[59], seed[60], seed[61], seed[62], seed[63]},
            _p{0}
        {
        }

        public: xorshift4096star(const xorshift4096star& r):
            xorshift4096star{r._seed}
        {
            _p = r._p;
        }

        public: xorshift4096star(xorshift4096star&& r):
            xorshift4096star{r._seed}
        {
            _p = r._p;
        }

        public: xorshift4096star& operator=(const xorshift4096star& r)
        {
            std::copy(r._seed, r._seed + 64, _seed);
            _p = r._p;

            return *this;
        }

        public: xorshift4096star& operator=(xorshift4096star&& r)
        {
            std::copy(r._seed, r._seed + 64, _seed);
            _p = r._p;

            return *this;
        }

        public: ~xorshift4096star()
        {
        }
#pragma endregion

#pragma region Observers
        public: const seed_type* seed() const
        {
            return _seed;
        }
#pragma endregion

#pragma region Helpers
#pragma endregion

#pragma region Mutators
        public: result_type sample() const
        {
            auto s0 = _seed[ _p ];
            _p = ( _p + 1 ) & 63;
            auto s1 = _seed[ _p ];

            s1 ^= s1 << shift_a;
            s1 ^= s1 >> shift_b;
            s0 ^= s0 >> shift_c;
            return ( _seed[ _p ] = s0 ^ s1 ) * mult;
        }

        public: float number() const
        {
            return float(sample()) * norm;
        }

        public: void skip(seed_type ns) const;
#pragma endregion
    };
}
