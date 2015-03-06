// -*- C++ -*-

#include "xorshift4096star.hpp"

namespace OTI
{
    const xorshift4096star::seed_type xorshift4096star::default_seed[] { 3001ULL, 3079ULL, 3257ULL, 3511ULL,
                                                                         4001ULL, 4057ULL, 4507ULL, 4583ULL,
                                                                         5003ULL, 5281ULL, 5861ULL, 5987ULL,
                                                                         6007ULL, 6229ULL, 6301ULL, 7901ULL,
                                                                         3001ULL, 3079ULL, 3257ULL, 3511ULL,
                                                                         4001ULL, 4057ULL, 4507ULL, 4583ULL,
                                                                         5003ULL, 5281ULL, 5861ULL, 5987ULL,
                                                                         6007ULL, 6229ULL, 6301ULL, 7901ULL,
                                                                         3001ULL, 3079ULL, 3257ULL, 3511ULL,
                                                                         4001ULL, 4057ULL, 4507ULL, 4583ULL,
                                                                         5003ULL, 5281ULL, 5861ULL, 5987ULL,
                                                                         6007ULL, 6229ULL, 6301ULL, 7901ULL,
                                                                         3001ULL, 3079ULL, 3257ULL, 3511ULL,
                                                                         4001ULL, 4057ULL, 4507ULL, 4583ULL,
                                                                         5003ULL, 5281ULL, 5861ULL, 5987ULL,
                                                                         6007ULL, 6229ULL, 6301ULL, 7901ULL };

    void xorshift4096star::skip(seed_type ns) const
    {
        while (ns)
        {
            sample();
            --ns;
        }
    }
}
