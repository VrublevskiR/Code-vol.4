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
    vector<int> array1;
    vector<int> array2;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        array1.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        array2.push_back(a);
    }

    cout << "Vector1: " << array1 << endl;
    cout << "Vector2: " << array2 << endl;

    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    vector<int> si;
    set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), inserter(si, si.end()));

    sort(si.begin(), si.end());
    auto it = unique(si.begin(), si.end());
    si.erase(it, si.end());

    cout << "si: " << si << endl;
    return 0;
}