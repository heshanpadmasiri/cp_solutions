#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

bool isInSeries(int val, int start, int d) { return (val - start) % d == 0; }

void solve(int n, int x, int y) {
  int curr_max = INF;
  int min_s, min_d;
  for (int start = 1; start <= x; start++) {
    for (int d = 1; d <= (y - x); d++) {
      int max = (n - 1) * d + start;
      if (isInSeries(x, start, d) && isInSeries(y, start, d) && y <= max) {
        if (max < curr_max) {
          curr_max = max;
          min_s = start;
          min_d = d;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (i * min_d) + min_s << " ";
  }
  cout << endl;
}

int main() {
  int t, n, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    solve(n, x, y);
  }
  return 0;
}
