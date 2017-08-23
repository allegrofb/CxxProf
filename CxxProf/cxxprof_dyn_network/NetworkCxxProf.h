
#ifndef _NETWORK_CXXPROF_H_
#define _NETWORK_CXXPROF_H_

#include <stack>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include "AppInfo.h"
#include "NetworkActivity.h"
#include "NetworkObjects.h"
#include "../IDynCxxProf.h"


namespace CxxProf
{

    class NetworkCxxProf : public IDynCxxProf
    {
    public:
        NetworkCxxProf();
        virtual ~NetworkCxxProf();

        boost::shared_ptr<IActivity> createActivity(const std::string& name);
        void addMark(const std::string& name);
        void addPlotValue(const std::string& name, double value);
        void setProcessAlias(const std::string name);
        void setThreadAlias(const std::string name);
        void shutdown();

        std::string toString() const;

    private:
        void addResult(const ActivityResult& result);
        boost::mutex callbackMutex_;

        /**
         * Tries to create a somehw unique ID for the App
         * The name needs to be unique for several processes on the same host
         * as well as for several processes on different hosts.
         */
        std::string getAppname(const std::string& appName);
        AppInfo info_;

        bool isSending_;
        boost::thread sendThread_;
        boost::mutex sendMutex_;
		boost::mutex storeMutex_;
		void sendLoop();
        void sendObjects();

        unsigned int actCounter_;
        std::stack<unsigned int> activeActivity_;
        std::map<unsigned int, boost::weak_ptr<NetworkActivity> > activities_;
        boost::posix_time::ptime profilingStart_;
        std::vector<boost::thread::id> knownThreads_;
        /**
         * Returns the current Thread Id, creates it if the current thread has no Id yet
         */
        unsigned int checkThreads();

        NetworkObjects networkObjects[2];
		int currentObject = 0;
		NetworkObjects* sendObjects_ = &networkObjects[0];

    };

}

#endif //_NETWORK_CXXPROF_H_
