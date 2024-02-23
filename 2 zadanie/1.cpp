#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

bool is_simple(int m)
{
    int n = 1000000;
    bool prime[n + 1];
    std::memset(prime, true, sizeof(prime)); // заполнить массив prime эл-тами true

    std::vector<int> simple;
    int i = 0;

    if (m == 1)
    {
        return true;
    }

    for (int p = 2; p * p <= n; p++) // находим простые числа и убираем из массива числа кратные им
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (prime[p] == true)
        {
            simple.push_back(p);
            i++;
        }
    }

    for (int i = 0; i < size(simple); i++)
    {
        if (simple[i] == m)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        if (is_simple(i))
        {
            cout << i << ' ';
        }
    cout << endl;
    return 0;
}