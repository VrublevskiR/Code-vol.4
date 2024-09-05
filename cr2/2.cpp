#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> words;
    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;
        words.insert(word);
    }

    vector<string> new_words;
    for (const auto &word : words)
    {
        new_words.push_back(word);
    }

    sort(new_words.begin(), new_words.end(), [](const string &a, const string &b)
         { return a.size() > b.size(); });

    for (const auto &word : new_words)
    {
        cout << word << endl;
    }

    return 0;
}
