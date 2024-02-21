#include <iostream>
using namespace std;

int main()
{
    int n, k = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        for (int i = 0; i < k; i++)
        {
            cout << "+";
        }
        k++;
        cout << endl;
    }
    return 0;
}