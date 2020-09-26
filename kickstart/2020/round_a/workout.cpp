#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define INF 1000000

int solve() {
  int n, k, tmp;
  cin >> n >> k;
  vector<int> times;
  times.reserve(n);
  int max_diff = 0;
  int min_diff = 1;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    times.push_back(tmp);
    if (i) {
      int diff = times[i] - times[i - 1];
      max_diff = max(diff, max_diff);
    }
  }
  int diff = max_diff;
  while (diff > 1) {
    float new_diff = floor((max_diff + min_diff) / 2.0);
    int c = 0;
    for (int i = 1; i < n; i++) {
      float d = times[i] - times[i - 1];
      c += ceil(d / new_diff) - 1;
    }
    if (c <= k) {
      diff = new_diff;
      if (new_diff == max_diff) {
        break;
      }
      max_diff = new_diff;
    } else {
      if (new_diff == min_diff) {
        break;
      }
      min_diff = new_diff;
    }
  }
  return diff;
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
