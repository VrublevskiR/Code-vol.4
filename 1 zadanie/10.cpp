#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*int num_mn(int n) // подсчет числа множителей числа n
{
    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            j++;
        }
    }
    return j;
}

#include <iostream>
using namespace std;

int main() // один непонятный пример
{
    int m, i = 0, k = 2;
    cin >> m;

    while (i < m)
    {
        if (num_mn(k) == 2)
        {
            i++;
        }
        k++;
    }

    cout << k - 1;

    return 0;
}*/

int Prime_number(int m)
{
    int n = 1000000;
    bool prime[n + 1];
    std::memset(prime, true, sizeof(prime)); // заполнить массив prime эл-тами true

    std::vector<int> simple;
    int i = 0;

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
    return simple[m - 1];
}

int main()
{
    int m;
    cin >> m;
    cout << Prime_number(m);
    return 0;
}