#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int *binary_recursion(unsigned int n) // рекурсионный метод перевода в 2ное исчисление + возвращение функцией массива
{
    static int arr[2] = {0, 0};
    if (n == 1)
    {
        arr[0] += 1;
        return arr;
    }
    if (n == 0)
    {
        arr[1] += 1;
        return arr;
    }
    if (n % 2 == 1)
    {
        arr[0] += 1;
    }
    if (n % 2 == 0)
    {
        arr[1] += 1;
    }
    binary_recursion(n / 2);
}

int main()
{
    int n;
    cin >> n;
    int *ptr = binary_recursion(n);

    for (int i = 0; i < ptr[0]; i++)
    {
        cout << "1";
    }

    for (int i = 0; i < ptr[1]; i++)
    {
        cout << "0";
    }

    return 0;
}