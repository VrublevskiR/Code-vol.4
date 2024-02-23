#include <iostream>
using namespace std;

char get_a_letter()
{
    char k;
    cin >> k;
    return k;
}

char unleveling(char c)
{
    if (c >= 'a' && c <= 'z')
        c += 'A' - 'a';
    return c;
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << unleveling(get_a_letter());
    cout << endl;
    return 0;
}