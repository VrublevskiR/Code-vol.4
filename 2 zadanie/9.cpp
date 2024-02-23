#include <iostream>
using namespace std;

char leveling(char c)
{
    if (c >= 65 && c <= 90)
    {
        return c + 32;
    }
    else
    {
        return c;
    }
}

int main()
{
    char c;
    do
    {
        cin.get(c);
        cout << leveling(c);
    } while (c != '\n');
    cout << endl;
    return 0;
}