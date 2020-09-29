#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

void solve() {
  int N, X, tmp;
  cin >> N >> X;
  vector<int> a;
  a.reserve(N);
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }
  map<double, vector<int>> round_map;
  for (int i = 0; i < N; i++) {
    int each = a[i];
    double rounds = ceil(double(each) / double(X));
    if (round_map.find(rounds) != round_map.end()) {
      round_map[rounds].push_back(i + 1);
    } else {
      vector<int> t;
      t.push_back(i + 1);
      round_map[rounds] = t;
    }
  }
  for (auto each : round_map) {
    for (auto e : each.second) {
      cout << e << ' ';
    }
  }

  int main() {
    _fast_;
    int t;
    cin >> t;
    int i = 1;
    while (t--) {
      cout << "Case #" << i << ": ";
      solve();
      cout << endl;
      i++;
    }
    return 0;
  }
