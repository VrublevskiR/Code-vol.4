#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

// Вывод vector-а чисел
ostream &operator<<(ostream &os, const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        os << *it << " ";
    return os;
}

int main()
{
    int n, a;
    cin >> n;
    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        array.push_back(a);
    }

    cout << "Vector: " << array << endl;

    reverse(array.begin(), array.end());
    cout << "Vector after reverse: " << array << endl;
    return 0;
}