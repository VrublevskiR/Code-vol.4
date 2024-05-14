#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(int a, int b)
{
    if (a % 2 == 0 && b % 2 == 0)
    {
        return a > b;
    }
    else if (a % 2 != 0 && b % 2 != 0)
    {
        return a < b;
    }
    else
    {
        return a % 2 != 0;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::stable_sort(arr.begin(), arr.end(), cmp);

    for (int num : arr)
    {
        std::cout << num << " ";
    }

    return 0;
}
