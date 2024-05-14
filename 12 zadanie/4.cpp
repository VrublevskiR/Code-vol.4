#include <iostream>
#include <unordered_map>
#include <limits>
#include <string>

using namespace std;

class TelemetryController
{
private:
    unordered_map<string, unsigned int> eventsCount;
    unordered_map<string, long> minValue;
    unordered_map<string, long> maxValue;

public:
    void handleEvent(const string &device, long value)
    {
        eventsCount[device]++;
        if (eventsCount[device] == 1)
        {
            minValue[device] = value;
            maxValue[device] = value;
        }
        else
        {
            minValue[device] = min(minValue[device], value);
            maxValue[device] = max(maxValue[device], value);
        }
    }

    unsigned int getEventsCount(const string &device) const
    {
        if (eventsCount.find(device) != eventsCount.end())
            return eventsCount.at(device);
        else
            return 0;
    }

    long getMinValue(const string &device) const
    {
        if (minValue.find(device) != minValue.end())
            return minValue.at(device);
        else
            return numeric_limits<long>::min();
    }

    long getMaxValue(const string &device) const
    {
        if (maxValue.find(device) != maxValue.end())
            return maxValue.at(device);
        else
            return numeric_limits<long>::max();
    }
};

int main()
{
    TelemetryController tc;
    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", -42);
    tc.handleEvent("d2", 100);

    cout << "Events count for d1: " << tc.getEventsCount("d1") << endl;
    cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
    cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;

    return 0;
}
