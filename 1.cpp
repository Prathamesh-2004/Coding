#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end, index;
};

bool compare(Activity a, Activity b) {
    if (a.end == b.end) return a.index < b.index; // tie-breaking by index
    return a.end < b.end; // sort by finish time
}

int main() {
    int n;
    cin >> n;
    vector<Activity> activities(n);

    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end;
        activities[i].index = i + 1; // 1-based indexing
    }

    // sort by finish time
    sort(activities.begin(), activities.end(), compare);

    vector<int> selected;
    int last_end = -1;

    for (int i = 0; i < n; i++) {
        if (activities[i].start >= last_end) {
            selected.push_back(activities[i].index);
            last_end = activities[i].end;
        }
    }

    cout << selected.size() << "\n";
    for (int idx : selected) cout << idx << " ";
    cout << "\n";

    return 0;
}
