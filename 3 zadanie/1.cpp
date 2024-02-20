#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    float b;

    for (int i = 0; i < n; i++)
    {
        b = b + a[i];
    }

    b = b / n;
    cout << "Среднее арифметическое:" << b << endl;

    for (int i = 0; i < n; i++) // вывод чисел больших ср. арифм.
    {
        if (a[i] > b)
            cout << a[i] << " ";
    }
    return 0;
}