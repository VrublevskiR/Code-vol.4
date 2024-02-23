#include <iostream>
using namespace std;

unsigned long long int fibonacci(unsigned int n)
{
    unsigned long long int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
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
    cout << sum_of_numbers(fibonacci(n)) << endl;
    return 0;
}