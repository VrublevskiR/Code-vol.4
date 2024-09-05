#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

const std::string NO_DATA = "no data";

int main()
{
    int n;
    cin >> n;

    map<string, map<uint64_t, string>> objects;
    map<string, map<uint64_t, set<string>>> locations;

    for (int i = 0; i < n; ++i)
    {
        string object, location;
        uint64_t timestamp;
        cin >> object >> location >> timestamp;

        objects[object][timestamp] = location;
        locations[location][timestamp].insert(object);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        string type;
        cin >> type;

        if (type == "object")
        {
            string object;
            uint64_t timestamp;
            cin >> object >> timestamp;

            auto it = objects[object].upper_bound(timestamp);
            if (it != objects[object].begin())
            {
                --it;
                cout << it->second << endl;
            }
            else
            {
                cout << NO_DATA << endl;
            }
        }
        else if (type == "location")
        {
            string location;
            uint64_t timestamp;
            cin >> location >> timestamp;

            auto it = locations[location].upper_bound(timestamp);
            if (it != locations[location].begin())
            {
                --it;
                for (const auto &object : it->second)
                {
                    cout << object << ' ';
                }
                cout << endl;
            }
            else
            {
                cout << NO_DATA << endl;
            }
        }
    }

    return 0;
}