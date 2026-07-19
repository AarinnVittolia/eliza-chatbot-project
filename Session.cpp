#include "Session.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool SessionList::loadSessions(string filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Cannot open session file.\n";
        return false;
    }

    sessions.clear();

    string line;

    while (getline(fin, line))
    {
        Session s;

        stringstream ss(line);

        getline(ss, s.id, ',');
        getline(ss, s.username, ',');
        getline(ss, s.contact, ',');
        getline(ss, s.start, ',');
        getline(ss, s.end, ',');

        sessions.push_back(s);
    }

    fin.close();

    cout << sessions.size() << " sessions loaded.\n";

    return true;
}
