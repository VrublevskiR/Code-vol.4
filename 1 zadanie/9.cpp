#include <iostream>
using namespace std;

int main()
{
    char k;
    int i = 0;

    while (cin >> k && (k == '1' || k == '0')) //(ввод, пока вводим допустимы элемент)&&(элемент 1 или 0)

    /*  while (cin >> k) такой код при введении в сhar k значение abc выведет abc (бесконечный ввод, не реагирует на пробелы и enter)
        {
            cout << k;
        }*/

    {
        if (k == '1')
        {
            i++;
        }
    }
    cout << i;
    return 0;
}