#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> notes(n);
  for (int i = 0; i < n; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    notes[i] = {t1, t2};
  }

  int fingers = 0;
  int current_time = 0;

  for (const auto& note : notes) {
    if (note.first >= current_time) {
      ++fingers;
      current_time = note.second;
    }
  }

  cout << fingers << endl;

  return 0;
}