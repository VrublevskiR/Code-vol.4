#include <iostream>
using namespace std;

int GCD(int a, int b) // Наименьший общий делитель
{
    while (a - b != 0)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main()
{

    int a, b, c, nok_ab, nok_abc;

    cin >> a >> b >> c;

    nok_ab = (a * b) / GCD(a, b); // Формула НОК(а, b) = (а * b) / НОД(а, b)
    nok_abc = (nok_ab * c) / GCD(nok_ab, c);

    cout << nok_abc << endl;
    return 0;
}