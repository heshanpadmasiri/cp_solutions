#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

int solve() {
  int K, tmp, last;
  last = -1;
  cin >> K;
  vector<int> data;
  data.reserve(K);
  for (int i = 0; i < K; i++) {
    cin >> tmp;
    if (tmp != last) {
      data.push_back(tmp);
    }
    last = tmp;
  }
  int violations, ups, downs;
  violations = 0;
  ups = 0;
  downs = 0;
  for (int i = 1; i < K; i++) {
    if (data[i] > data[i - 1]) {
      ups++;
      downs = 0;
    } else {
      downs++;
      ups = 0;
    }
    if (ups > 3 || downs > 3) {
      violations++;
      ups = downs = 0;
    }
  }
  return violations;
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
