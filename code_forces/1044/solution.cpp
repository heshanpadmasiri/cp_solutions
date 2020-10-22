#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, tmp, val, tmp2;
  cin >> n >> m;
  vector<int> vertical;
  vertical.reserve(n);
  vector<int> horizontal;
  horizontal.reserve(m);
  for (int i = 0; i < n; i++) {
    cin >> val;
    // cout << val << endl;
    vertical.push_back(val);
  }
  vertical.push_back(1e9);
  for (int i = 0; i < m; i++) {
    cin >> tmp >> val >> tmp2;
    if (tmp == 1) {
      horizontal.push_back(val);
    }
  }
  m = horizontal.size();
  sort(vertical.begin(), vertical.end());
  sort(horizontal.begin(), horizontal.end());
  // for (auto each : vertical) {
  // cout << each << endl;
  //}
  int ans = INT_MAX;
  int h_id = 0;
  if (n == 0) {
    while (h_id < m && horizontal[h_id] < 1e9) {
      h_id++;
    }
    ans = m - h_id;
  } else {
    for (int i = 0; i <= n; i++) {
      int bound = vertical[i];
      while (h_id < m && horizontal[h_id] < bound) {
        h_id++;
      }
      int count = m - h_id + i;
      // cout << i << ',' << bound << ',' << h_id << ',' << count << endl;
      ans = min(ans, count);
    }
  }
  cout << ans << endl;
  return 0;
}
