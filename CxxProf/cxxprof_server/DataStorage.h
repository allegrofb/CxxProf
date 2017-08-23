
#ifndef _DATA_STORAGE_H_
#define _DATA_STORAGE_H_

#include "../cxxprof_dyn_network/NetworkObjects.h"

#include <boost/shared_ptr.hpp>
#include <sqlite3cc.h>

class DataStorage
{
public:
    /**
     * Creates a new database and stores the needed tables in it
     *  * Activities
     *  * Marks
     *  * Plots
     */
    DataStorage();
    virtual ~DataStorage();

    /**
     * Stores the given objects into the database
     */
    void storeResult(const CxxProf::NetworkObjects& objects);

private:
    /**
     * Initializes a new database with the given name for
     *  * Activities
     *  * Marks
     *  * Plots
     */
    void initDatabase(const std::string& filename);
    /**
     * This function returns the current DateStr in the following form:
     * DDMonYYYY_HHMMSS -> 31Apr2014_235959
     */
    std::string getCurrentDateStr();
    /**
    * Checks if the AppInfo has been added yet, then adds it if needed
    * Returns: The AppId which is given for this app
    */
    unsigned int updateAppInfo(const CxxProf::AppInfo& info);
    /**
    * Adds the marks to the database
    */
    void updateMarks(const std::vector<CxxProf::NetworkMark>& marks, unsigned int appId);
    /**
    * Adds the plots to the database
    */
    void updatePlots(const std::vector<CxxProf::NetworkPlot>& plots, unsigned int appId);
    /**
     * Adds the activities to the database
     */
    void updateActivities(const std::vector<CxxProf::ActivityResult>& activities, unsigned int appId);
    /**
     * Checks if the ThreadInfo has been added yet, adds and updates it if needed
     */
    void updateThreadInfo(const CxxProf::AppInfo& info, unsigned int appId);

    /**
     * This is the connection to the database
     */
    boost::shared_ptr<sqlite::connection> connection_;

};

extern DataStorage storage_;

#endif //_DATA_STORAGE_H_
