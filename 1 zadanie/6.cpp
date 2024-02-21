#include <iostream>
using namespace std;

int main() // не учел 0
{
    int n;
    cin >> n;
    int fact = n;

    for (int i = 0; i < n; i++)
    {
        fact = fact * (n - 1);
        n--;
    }

    cout << fact;
    return 0;
}