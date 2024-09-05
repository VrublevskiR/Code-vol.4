#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Event
{
    long long timestamp;
    string action, property, value;
};

int main()
{
    int n;
    cin >> n;
    vector<Event> events(n);
    for (int i = 0; i < n; i++)
    {
        cin >> events[i].timestamp >> events[i].action >> events[i].property >> events[i].value;
    }

    int m;
    cin >> m;
    vector<long long> requests(m);
    for (int i = 0; i < m; i++)
    {
        cin >> requests[i];
    }

    map<long long, map<string, string>> state;
    set<string> fields;
    for (const Event &event : events)
    {
        if (event.action == "SET")
        {
            state[event.timestamp + 1][event.property] = event.value;
            fields.insert(event.property);
        }
        else if (event.action == "DELETE")
        {
            state[event.timestamp + 1].erase(event.property);
            fields.erase(event.property);
        }
    }

    for (const long long &timestamp : requests)
    {
        vector<pair<string, string>> result;
        for (const string &field : fields)
        {
            if (state[timestamp].count(field))
            {
                result.emplace_back(field, state[timestamp][field]);
            }
        }
        sort(result.begin(), result.end());
        for (const auto &[field, value] : result)
        {
            cout << field << " : " << value << ", ";
        }
        cout << endl;
    }

    return 0;
}