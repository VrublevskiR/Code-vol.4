#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class SessionManager
{
public:
    void login(const string &username)
    {
        activeUsers.insert(username);
    }

    void logout(const string &username)
    {
        activeUsers.erase(username);
    }

    int getNumberOfActiveUsers() const
    {
        return activeUsers.size();
    }

private:
    unordered_set<string> activeUsers;
};

int main()
{
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;

    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;

    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;

    m.logout("whoever");
    cout << m.getNumberOfActiveUsers() << endl;

    m.logout("alice");
    cout << m.getNumberOfActiveUsers() << endl;

    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;

    return 0;
}
