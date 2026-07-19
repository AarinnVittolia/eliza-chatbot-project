#ifndef REGION_H
#define REGION_H

#include <vector>
#include <string>

using namespace std;

// Holds the initial layout of ELIZA chat session slots as a grid.
// Each cell holds a session ID, "-1" for an empty/available slot, or
// "R" for a reserved slot. Modeled directly on the Garage class from
// the QParking project.
class Region
{
private:
    vector<vector<string>> layout;

public:
    bool loadRegion(string filename, int rows, int cols);
    void displayRegion();
    void saveRegion(string filename);
};

#endif
