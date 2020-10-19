#include <bits/stdc++.h>
#define N 1000000
using namespace std;

void solve() {
  long n, k;
  string tmp;
  cin >> n >> k;
  cin >> tmp;
  bitset<N> bs(tmp);

  bitset<N> mask;
  int cnt = 0;

  for (long i = n - 1; i >= 0; i--) {
    if (bs[i]) {
      cnt++;
    } else if (!bs[i] && cnt > 0) {
      mask.set();
      long j = cnt <= k ? cnt : k;
      k -= j;
      j += i;
      mask[j] = 0;
      bs &= mask;
      bs[i] = 1;
      if (k <= 0) {
        break;
      }
    }
  }

  for (long i = n - 1; i >= 0; i--) {
    cout << bs[i];
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
