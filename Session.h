#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <string>

using namespace std;

// A single registered ELIZA chat session record. Modeled directly on
// the Customer struct from the QParking project.
struct Session
{
    string id;
    string username;
    string contact;
    string start;
    string end;
};

class SessionList
{
private:
    vector<Session> sessions;

public:
    bool loadSessions(string filename);
};

#endif
