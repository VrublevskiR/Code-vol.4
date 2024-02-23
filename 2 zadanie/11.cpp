#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

unsigned int get_a_hexadecimal()
{
    char k;
    unsigned int res = 0;
    vector<char> arr1;
    vector<int> arr2;

    while (cin >> k)
    {
        if ((k < '0') || (k > '9' && k < 'A') || (k > 'F')) // проверка символа на корректность
        {
            return 0;
        }

        {
            arr1.push_back(k);
        }

        char temp;
        if ((temp = getchar()) == '\n') // забрали из ввода символ
        {
            break; // выходим из цикла
        }

        ungetc(temp, stdin); // если все ок возвращаем символ обратно в стандартрный поток ввода
    }

    for (int i = 0; i < size(arr1); i++) // перевод из char в int
    {
        switch (arr1[i])
        {
        case '0':
            arr2.push_back(0);
            break;
        case '1':
            arr2.push_back(1);
            break;
        case '2':
            arr2.push_back(2);
            break;
        case '3':
            arr2.push_back(3);
            break;
        case '4':
            arr2.push_back(4);
            break;
        case '5':
            arr2.push_back(5);
            break;
        case '6':
            arr2.push_back(6);
            break;
        case '7':
            arr2.push_back(7);
            break;
        case '8':
            arr2.push_back(8);
            break;
        case '9':
            arr2.push_back(9);
            break;
        case 'A':
            arr2.push_back(10);
            break;
        case 'B':
            arr2.push_back(11);
            break;
        case 'C':
            arr2.push_back(12);
            break;
        case 'D':
            arr2.push_back(13);
            break;
        case 'E':
            arr2.push_back(14);
            break;
        case 'F':
            arr2.push_back(15);
            break;
        }
    }

    for (int i = 0; i < size(arr2); i++) // перевод из 16ти в 10ное исчисление
    {
        res += arr2[i] * pow(16, size(arr2) - i - 1);
    }
    return res;
}

int main()
{
    cout << get_a_hexadecimal() << endl;
    return 0;
}