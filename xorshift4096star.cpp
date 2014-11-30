// -*- C++ -*-

#include "xorshift4096star.hpp"

namespace OTI
{
    void xorshift4096star::skip(uint64_t ns) const
    {
        while (ns)
        {
            sample();
            --ns;
        }
    }
}
