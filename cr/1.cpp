#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Vv, Vm, L, K, N;
    cin >> Vv >> Vm >> L >> K >> N; // L расстояние от пса, K расстояние до забора
    if (N > 0)
    {
        Vv = Vv - N + 1; // сразу скидываем мешок
    }
    while (true)
    {
        if (L <= 0)
        {
            N = 0;
            break;
        }
        if (K <= 0)
        {
            break;
        }
        K = K - Vv;
        L = L - Vm + Vv; // за ход
        if (N >= 1)
        {
            N -= 1;
            Vv++;
        }
    }
    cout << N;
    return 0;
}