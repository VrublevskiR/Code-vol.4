#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) // ввод матрицы
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << endl;

    for (int j = 0; j < n; j++) // транспонирование
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}