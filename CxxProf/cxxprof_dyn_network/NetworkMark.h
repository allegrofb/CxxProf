
#ifndef _NETWORK_MARK_H_
#define _NETWORK_MARK_H_

#include <boost/cstdint.hpp>
#include <stdint.h>
#include <string>

namespace CxxProf
{

    struct NetworkMark
    {
        std::string Name;
        boost::int64_t Timestamp;

        NetworkMark() :
            Name(""),
            Timestamp(0)
        {}
    };

}

#endif //_NETWORK_MARK_H_
