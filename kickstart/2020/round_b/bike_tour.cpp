#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

int solve() {
  int N, tmp;
  cin >> N;
  vector<int> heights;
  heights.reserve(N);
  while (N--) {
    cin >> tmp;
    heights.push_back(tmp);
  }
  int count = 0;
  for (int i = 1; i < (heights.size() - 1); i++) {
    if ((heights[i] > heights[i - 1]) && (heights[i] > heights[i + 1])) {
      count++;
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
