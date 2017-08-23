
#ifndef _NETWORK_PLOT_H_
#define _NETWORK_PLOT_H_

#include <boost/cstdint.hpp>
#include <stdint.h>
#include <string>

namespace CxxProf
{

    struct NetworkPlot
    {
        std::string Name;
        boost::int64_t Timestamp;
        double Value;

        NetworkPlot() :
            Name(""),
            Timestamp(0),
            Value(0.0)
        {}
    };

}

#endif //_NETWORK_PLOT_H_
