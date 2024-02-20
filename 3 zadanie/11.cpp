#include <iostream>
#include <vector>
#include <algorithm>

struct box // структура коробки
{
    int cost;
    int candy;
};

bool compare(box a, box b) // то, как сравнивает sort
{
    return a.cost < b.cost;
}

using namespace std;
int main()
{
    int n;

    vector<box> array;

    cin >> n;

    for (int i = 0; i < n; i++) // ввод коробок
    {
        array.push_back(box());
        cin >> array[i].cost;
        cin >> array[i].candy;
    }

    int money;
    cin >> money;

    sort(begin(array), end(array), compare);

    int i = 0, sum = 0; // алгоритм покупок
    while (i < n)
    {
        if (money - array[i].cost < 0)
        {
            break;
        }
        else
        {
            sum += array[i].candy;
            money -= array[i].cost;
            i++;
        }
    }

    cout << i << " " << sum;

    return 0;
}