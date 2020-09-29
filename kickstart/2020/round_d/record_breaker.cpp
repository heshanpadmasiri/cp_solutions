#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

void solve() {
  int N, tmp;
  cin >> N;
  vector<int> values;
  values.reserve(N);
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    values.push_back(tmp);
  }
  int larget, count;
  larget = -1;
  count = 0;
  for (int i = 0; i < N; i++) {
    if (values[i] > larget) {
      if ((i == N - 1) || (values[i + 1] < values[i])) {
        count++;
      }
    }
    larget = max(larget, values[i]);
  }
  cout << count;
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
