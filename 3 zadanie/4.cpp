#include <iostream>
#include <limits>
using namespace std;

int main()
{
  int n, m;

  cin >> n;
  cin >> m;

  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера ввода от символа окончания строки

  char a[n][m + 1];
  char b[m + 1];

  for (int i = 0; i < n; i++) // ввод массива строк
  {
    cin.getline(b, m + 1);
    for (int q = 0; q <= m + 1; q++)
    {
      a[i][q] = b[q];
    }
  }

  cout << endl;

  for (int i = m - 1; i >= 0; i--) // поворот на pi/2 пр. час. стр.
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[j][i];
    }
    cout << endl;
  }
  return 0;
}