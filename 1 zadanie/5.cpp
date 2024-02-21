#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "+";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "+";
        for (int i = 0; i < m - 2; i++)
        {
            cout << " ";
        }
        cout << "+";
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        cout << "+";
    }
    cout << endl;

    return 0;
}