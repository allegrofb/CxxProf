
#ifndef _APP_INFO_H_
#define _APP_INFO_H_

#include <boost/cstdint.hpp>
#include <map>
#include <stdint.h>
#include <string>

namespace CxxProf
{

    struct AppInfo
    {
        std::string Name;
        boost::int64_t Starttime;
        std::map<unsigned int, std::string> ThreadAliases;

        AppInfo() :
            Name(""),
            Starttime(0)
        {}
    };

}

#endif //_APP_INFO_H_
