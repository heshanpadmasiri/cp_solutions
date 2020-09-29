#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)
typedef pair<int, int> pi;
int solve() {
  int n, k, s, e;
  cin >> n >> k;
  priority_queue<pi, vector<pi>, greater<pi>> q;
  for (int i = 0; i < n; i++) {
    cin >> s >> e;
    pair<int, int> tmp = make_pair(s, e);
    q.push(tmp);
  }
  int count = 0;
  int end_time = -1;
  while (!q.empty()) {
    auto top = q.top();
    q.pop();
    auto start = top.first;
    auto end = top.second;
    if (start > end_time) {
      count++;
      end_time = start + k;
      cout << start << ":" << end_time << endl;
    }
    while (end > end_time) {
      int n = ceil(float(end - end_time) / float(k));
      count++;
      cout << end_time + 1 << ":";
      end_time = end_time + k;
      cout << end_time << endl;
    }
  }
  return count;
}

int main() {
  _fast_;
  int t;
  cin >> t;
  int i = 1;
  while (t--) {
    cout << "Case #" << i << ": " << solve() << endl;
    i++;
  }
  return 0;
}
