#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    list<int> deq;
    for (int i = 0; i < n; i++) {
        deq.push_back(a[i]);
    }
    int cur_max = -1;
    int cnt = 0;
    while (!deq.empty()) {
        int front = deq.front();
        int back = deq.back();
        int this_val = 0;
        if (front <= back) {
            deq.pop_front();
            this_val = front;
        }
        else {
            deq.pop_back();
            this_val = back;
        }
        if (this_val >= cur_max) {
            cur_max = this_val;
            cnt++;
        }

    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int _t = 0; _t < T; _t++) {
        cout << "Case #" << _t + 1 << ": ";
        testcase();
    }
}