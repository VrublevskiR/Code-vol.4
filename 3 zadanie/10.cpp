#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) // ввод масива
    {
        cin >> a[i];
    }

    int max_plus[n];
    int max_minus[n];

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

    int more0 = 0;
    for (int j = 0; j < n; j++)
    {
        maximum = a[0];
        for (int i = 0; i < n; i++) // нахождение j-го максимума
        {
            if (a[i] > maximum)
            {
                maximum = a[i];
            }
        }

        if (maximum >= 0)
        {
            more0 += 1;
            max_plus[j] = maximum;
        }
        else
        {
            max_minus[j - more0] = maximum;
        }

        for (int k = 0; k < n; k++) // уменьшение максимальных элементов масива
        {
            if (a[k] == maximum)
            {
                a[k] = min;
                break;
            }
        }
    }

    for (int i = more0 - 1; i >= 0; i--) // вывод m максимальных положительных элементов элементов
    {
        cout << max_plus[i] << " ";
    }

    for (int i = 0; i < n - more0; i++) // вывод m максимальных по модулю отрицательных элементов элементов
    {
        cout << max_minus[i] << " ";
    }
    return 0;
}

/*int main()
{
    int n, pos = 0;
    vector<int> a;

    cin >> n;
    for (int i = 0, temp = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    for (; a[pos] < 0 && pos < n; pos++)
        ;

    for (int i = pos; i < n; i++)
    {
        cout << a[i] << " ";
    }

    for (int i = pos - 1; i > -1; i--)
    {
        cout << a[i] << " ";
    }

    return 0;
}*/