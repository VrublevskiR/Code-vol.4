#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Tracker
{
private:
    unordered_map<string, unsigned long long> clickCounts;
    unordered_map<string, unsigned long long> firstClicks;
    unordered_map<string, unsigned long long> lastClicks;

public:
    void click(const string &username, unsigned long long timestamp)
    {
        clickCounts[username]++;
        if (clickCounts[username] == 1)
        {
            firstClicks[username] = timestamp;
        }
        lastClicks[username] = timestamp;
    }

    unsigned long long getClickCount(const string &username) const
    {
        return clickCounts.count(username) ? clickCounts.at(username) : 0;
    }

    unsigned long long getFirstClick(const string &username) const
    {
        if (firstClicks.count(username))
        {
            return firstClicks.at(username);
        }
        else
        {
            return 0;
        }
    }

    unsigned long long getLastClick(const string &username) const
    {
        if (lastClicks.count(username))
        {
            return lastClicks.at(username);
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);

    cout << t.getClickCount("alice") << endl;
    cout << t.getClickCount("bob") << endl;
    cout << t.getFirstClick("alice") << endl;
    cout << t.getFirstClick("bob") << endl;
    cout << t.getLastClick("alice") << endl;
    cout << t.getLastClick("bob") << endl;

    return 0;
}
