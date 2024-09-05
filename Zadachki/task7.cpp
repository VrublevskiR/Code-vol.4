#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Scan {
    int time_stamp;
    int id;
    double vit_d;
    double acat;
    double anti_tg;
    double neural_activity;
    double mch;
};

bool compare_by_id(const Scan& s1, const Scan& s2) {
    return s1.id < s2.id;
}

bool compare_by_neural_activity(const Scan& s1, const Scan& s2) {
    return s1.neural_activity < s2.neural_activity;
}

int main() {
    int n;
    cin >> n;

    vector<Scan> scans(n);
    for (int i = 0; i < n; i++) {
        cin >> scans[i].time_stamp >> scans[i].id >> scans[i].vit_d >> scans[i].acat >> scans[i].anti_tg >> scans[i].neural_activity >> scans[i].mch;
    }

    sort(scans.begin(), scans.end(), compare_by_id);

    int max_id = -1;
    double max_diff = -1;
    for (int i = 0; i < n; i++) {
        int current_id = scans[i].id;
        if (i != 0 && current_id != scans[i - 1].id) {
            double diff = scans[i - 1].neural_activity - scans[i - 1].neural_activity;
            if (diff > max_diff) {
                max_diff = diff;
                max_id = current_id;
            }
        }
    }

    cout << max_id << endl;

    return 0;
}