#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> unique_words;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        unique_words.insert(word);
    }

    vector<string> sorted_words;
    for (const auto& word : unique_words) {
        sorted_words.push_back(word);
    }

    sort(sorted_words.begin(), sorted_words.end(), [](const string& a, const string& b) {
        return a.size() > b.size();
    });

    for (const auto& word : sorted_words) {
        cout << word << endl;
    }

    return 0;
}
