#include <iostream>
using namespace std;

int main()
{
    int n1, n2;

    cin >> n1;
    cin >> n2;

    int a[n1][n2];
    int sum[n2] = {0};

    for (int i = 0; i < n1; i++) // ввод матрицы
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n2; i++) // суммирование столбцов
    {
        for (int j = 0; j < n1; j++)
        {
            sum[i] += a[j][i];
        }
    }

    int maximum = sum[0];
    for (int i = 0; i < n2; i++) // нахождение максимума
    {
        if (sum[i] > maximum)
        {
            maximum = sum[i];
        }
    }

    for (int i = 0; i < n2; i++) // Вывод  максимального столбца
    {
        if (sum[i] == maximum)
        {
            cout << i;
        }
    }

    return 0;
}