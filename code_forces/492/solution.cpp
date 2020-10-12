#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, tmp;
  scanf("%d %d", &n, &l);
  vector<int> lamps;
  lamps.reserve(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    lamps.push_back(tmp);
  }
  sort(lamps.begin(), lamps.end());
  double ans;
  double max_distance = -1;
  for (int i = 1; i < n; i++) {
    double d = lamps[i] - lamps[i - 1];
    max_distance = max(d, max_distance);
  }
  ans = max(max_distance / 2, (double)max(lamps[0], l - lamps[n - 1]));
  printf("%.9f\n", ans);
  return 0;
}
