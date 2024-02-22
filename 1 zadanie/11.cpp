#include <iostream>
using namespace std;

int main()
{
    int n, p;
    cin >> n;

    int q = ((n - 1) / 2);

    for (int i = 1; i <= q + 1; i++) // первая половина + центральная строчка
    {
        for (int j = (q - i + 1); j > 0; j--)
        {
            cout << " ";
        }
        for (p = 0; p < (2 * i - 1); p += 1)
        {
            cout << "+";
        }
        cout << endl;
    }

    for (int i = 1; i <= q; i++) // вторая половина
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        for (p = (2 * (q - 1) - 2 * i + 3); p > 0; p -= 1)
        {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}