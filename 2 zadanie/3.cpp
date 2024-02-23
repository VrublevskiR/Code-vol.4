#include <iostream>
using namespace std;

unsigned int sum_of_numbers(unsigned int n)
{
    int a = 0;
    while (n)
    {
        int number = n % 10;
        a = a + number;
        n /= 10;
    }
    return a;
}

int main()
{
    unsigned int n;
    cin >> n;
    cout << sum_of_numbers(n) << endl;
    return 0;
}