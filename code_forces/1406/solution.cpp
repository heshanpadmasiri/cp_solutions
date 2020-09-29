#include <bits/stdc++.h>
#define FILL -1000000000
using namespace std;

int main() {
  int t, n;
  long long tmp, ans;
  cin >> t;
  while (t--) {
    cin >> n;
    long long mx = -1e9;
    vector<long long> values;
    values.reserve(n);
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      values.push_back(tmp);
      mx = max(tmp, mx);
    }
    sort(values.begin(), values.end(),
         [](long long x, long long y) { return abs(x) > abs(y); });
    if (mx < 0) {
      cout << values[n] * values[n - 1] * values[n - 2] * values[n - 3] *
                  values[n - 4]
           << endl;
      continue;
    }
    ans = values[1] * values[2] * values[3] * values[4] * values[5];
    for (int i = 6; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        auto t = values[i];
        for (int k = 1; k <= 5; k++) {
          if (k != j) {
            t *= values[k];
          }
        }
        ans = max(ans, tmp);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
