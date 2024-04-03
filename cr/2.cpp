#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <string>

using namespace std;

int main()
{
    pair<int, int> Cat;
    int n, max;
    cin >> Cat.first >> Cat.second >> n; // начальный кот
    vector<pair<int, int>> Edit(n);      // его перемещения

    for (int i = 0; i < n; i++)
    {
        cin >> Edit[i].first;
        cin >> Edit[i].second;
    }

    max = abs(Cat.first - Cat.second);
    for (int i = 0; i < n; i++)
    {
        if (abs(Cat.first + Edit[i].first - Cat.second - Edit[i].second) > max)
        {
            max = abs(Cat.first + Edit[i].first - Cat.second - Edit[i].second);
        }
        Cat.first = Cat.first + Edit[i].first;
        Cat.second = Cat.second + Edit[i].second;
    }
    cout << max;
    return 0;
}