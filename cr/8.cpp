#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N;

    std::map<std::string, std::vector<int>> measurements;

    for (int i = 0; i < N; ++i)
    {
        std::string sensor_name;
        int value;
        std::cin >> sensor_name >> value;
        measurements[sensor_name].push_back(value);
    }

    for (auto &kv : measurements)
    {
        std::sort(kv.second.begin(), kv.second.end());
    }

    std::cin >> M;

    for (int i = 0; i < M; ++i)
    {
        std::string query_sensor;
        std::cin >> query_sensor;

        if (measurements.find(query_sensor) != measurements.end())
        {
            auto values = measurements[query_sensor];
            int median;

            if (values.size() % 2 == 0)
            {
                median = std::min(values[values.size() / 2 - 1], values[values.size() / 2]);
            }
            else
            {
                median = values[values.size() / 2];
            }

            std::cout << median << std::endl;
        }
        else
        {
            std::cout << "no data" << std::endl;
        }
    }

    return 0;
}