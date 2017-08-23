
#ifndef _NETWORK_OBJECTS_H_
#define _NETWORK_OBJECTS_H_

#include "AppInfo.h"
#include "NetworkMark.h"
#include "NetworkPlot.h"
#include "ActivityResult.h"
#include <vector>

namespace CxxProf
{

    struct NetworkObjects
    {
        AppInfo Info;
        std::vector<NetworkMark> Marks;
        std::vector<NetworkPlot> Plots;
        std::vector<ActivityResult> ActivityResults;

        void clear()
        {
            Marks.clear();
            Plots.clear();
            ActivityResults.clear();
        }

        unsigned int size() const
        {
            return Marks.size() + Plots.size() + ActivityResults.size();
        }
        unsigned int empty() const
        {
            return Marks.empty() || Plots.empty() || ActivityResults.empty();
        }
    };

}

#endif //_NETWORK_OBJECTS_H_
