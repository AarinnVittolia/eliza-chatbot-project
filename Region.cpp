#include "Region.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

bool Region::loadRegion(string filename, int /*rows*/, int /*cols*/)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Cannot open region file.\n";
        return false;
    }

    layout.clear();

    string line;

    while (getline(fin, line))
    {
        vector<string> row;
        string value;

        stringstream ss(line);

        while (getline(ss, value, ','))
        {
            row.push_back(value);
        }

        layout.push_back(row);
    }

    fin.close();

    return true;
}

void Region::displayRegion()
{
    cout << "\nInitial Session Region\n\n";

    for (auto row : layout)
    {
        for (auto value : row)
            cout << value << "\t";

        cout << endl;
    }
}

void Region::saveRegion(string filename)
{
    ofstream fout(filename);

    for (auto row : layout)
    {
        for (size_t i = 0; i < row.size(); i++)
        {
            fout << row[i];

            if (i < row.size() - 1)
                fout << ",";
        }

        fout << endl;
    }

    fout.close();
}
