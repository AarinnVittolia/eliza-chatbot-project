#include "Config.h"
#include <fstream>
#include <iostream>

using namespace std;

bool Config::readConfig(string filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Error opening configuration file.\n";
        return false;
    }

    fin >> rows >> cols;
    fin >> regionFile;
    fin >> sessionFile;

    fin.close();

    return true;
}

