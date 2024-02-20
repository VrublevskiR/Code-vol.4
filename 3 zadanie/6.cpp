#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int a[n], a1[n];

    for (int i = 0; i < n; i++) // ввод масива + создание копии а1[]
    {
        cin >> a[i];
        a1[i] = a[i];
    }

    cin >> m;
    int max[m];

    int maximum, min;

    min = a[0];
    for (int i = 0; i < n; i++) // нахождение минимума масива
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    if (min >= 0)
    {
        min = 0;
    } // уменьшение переменной min
    else
    {
        min = min * 2;
    }

    for (int j = 0; j < m; j++)
    {
        maximum = a[0];
        for (int i = 0; i < n; i++) // нахождение j-го максимума
        {
            if (a[i] > maximum)
            {
                maximum = a[i];
            }
        }

        max[j] = maximum;

        for (int k = 0; k < n; k++) // уменьшение максимальных элементов масива
        {
            if (a[k] == maximum)
            {
                a[k] = min;
                break;
            }
        }
    }

    for (int i = 0; i <= n; i++) // вывод в хронологическом порядке
    {
        for (int j = 0; j < m; j++)
        {
            if (a1[i] == max[j])
            {
                cout << a1[i] << " ";
                max[j] = min;
                break;
            }
        }
    }
    return 0;
}
// решение через вектор
/*int main()
{
    int n, m;
    vector<int> a;
    vector<int> b;

    cin >> n;

    for (int i = 0, temp = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
        b.push_back(temp);
    }

    sort(a.begin(), a.end(), greater<int>());

    cin >> m;
    auto begin = a.cbegin();
    auto end = a.cend();
    a.erase(begin + m, end);

    for (int i = 0; i < n; i++) //вывод в хронологическом порядке
    {
        auto it = find(a.begin(), a.end(), b[i]);
        if (it != a.end())
        {
            cout << b[i] << " ";
            a.erase(it);
        }
    }

    return 0;
} */