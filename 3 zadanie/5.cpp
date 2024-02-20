#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) // ввод масива
    {
        cin >> a[i];
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

    for (int i = m - 1; i >= 0; i--) // вывод m максимальных элементов
    {
        cout << max[i] << " ";
    }

    return 0;
}

// решение через вектор
/*
int main()
{
    int n, m;
    vector<int> a;

    cin >> n;

    for (int i = 0, temp = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end(), greater<int>());

    cin >> m;

    for (int i = m - 1; i > -1; i--)
    {
        cout << a[i] << " ";
    }

    return 0;
}*/