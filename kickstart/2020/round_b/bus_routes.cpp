#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

bool is_valid(vector<long> &X, long d, long D) {
  long last = d;
  for (auto each : X) {
    if (last % each == 0) {
      continue;
    }
    if (each < last) {
      long idx = (last / each) + 1;
      long next = each * idx;
      last = next;
    } else {
      last = each;
    }
    if (last > D) {
      return false;
    }
  }
  return true;
}

long solve() {
  long N, tmp;
  long D;
  cin >> N >> D;
  vector<long> X;
  X.reserve(N);
  while (N--) {
    cin >> tmp;
    X.push_back(tmp);
  }
  long high = D;
  long low = 1;
  long d = high;
  long max_d = low;
  while (low < high) {
    if (is_valid(X, d, D)) {
      max_d = d;
      low = d;
    } else {
      high = d;
    }
    long new_d = low + ((high - low) / 2);
    if (new_d == d) {
      break;
    }
    d = new_d;
  }
  return max_d;
  // for (long d = D; d > 0; d--) {
  // if (is_valid(X, d, D)) {
  // return d;
  //}
  //}
  // return 0;
}

int main() {
  _fast_;
  long t;
  cin >> t;
  long i = 1;
  while (t--) {
    cout << "Case #" << i << ": " << solve() << endl;
    i++;
  }
  return 0;
}
