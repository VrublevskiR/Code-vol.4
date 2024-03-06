#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, n, sum = 0, average, k = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    average = sum / size(arr);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > average)
        {
            k++;
        }
    }

    cout << k << endl;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > average)
        {
            cout << i << " ";
        }
    }
}