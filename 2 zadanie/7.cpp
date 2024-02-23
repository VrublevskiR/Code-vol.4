#include <iostream>
using namespace std;

unsigned long long int nonacci(unsigned int n)
{
    unsigned long long int arr[n];
    for (int i = 0; i < 7; i++)
    {
        arr[i] = 0;
    }
    arr[7] = 1;
    arr[8] = 1;
    for (int i = 9; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4] + arr[i - 5] + arr[i - 6] + arr[i - 7] + arr[i - 8] + arr[i - 9];
    }
    return arr[n - 1];
}

unsigned int sum_of_numbers(unsigned long long int n)
{
    unsigned int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main()
{
    unsigned int n;
    cin >> n;
    cout << sum_of_numbers(nonacci(n)) << endl;
    return 0;
}