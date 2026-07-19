#ifndef CONFIG_H
#define CONFIG_H

#include <string>

using namespace std;

// Reads the top-level configuration for the ELIZA session manager:
// how big the session grid is, and which files hold the initial
// region layout and the registered session records. Modeled directly
// on the Config class from the QParking project.
class Config
{
public:
    int rows;
    int cols;
    string regionFile;
    string sessionFile;

    bool readConfig(string filename);
};

#endif

