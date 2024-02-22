#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void binary_recursion(unsigned int n) // перевод числа из 10ти в 2ное исчисление
{
    if (n == 1)
    {
        cout << "1";
        return;
    }
    if (n == 0)
    {
        cout << "0";
        return;
    }
    binary_recursion(n / 2);
    cout << n % 2;
}

int main()
{
    int n;
    cin >> n;
    binary_recursion(n);
    return 0;
}