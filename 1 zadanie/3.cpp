#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            cout << "+";
        }
        cout << endl;
    }
    return 0;
}