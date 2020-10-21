#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string data;
  cin >> data;
  int last = 0;
  char last_c;
  int count = 0;
  bool tmp = true;
  for (int i = 0; i < n; i++) {
    char c = data[i];
    if (i == 0) {
      last = 0;
      last_c = c;
      continue;
    }
    if (c != last_c) {
      tmp = false;
      int d = i - last;
      // cout << i << ':' << d << '=' << d / 3 << endl;
      count += d / 3;
      last = i;
      last_c = c;
    } else if (i == n - 1) {

      int d = i - last + 1;
      // cout << i << ':' << d << '=' << d / 3 << endl;
      count += d / 3;
      last = i;
      last_c = c;
    }
  }
  if (data[0] == data[n - 1] && n >= 3) {
    int left = 0;
    while (data[left] == data[0]) {
      left++;
    }
    count -= left / 3;
    int right = 1;
    while (data[n - right] == data[0]) {
      right++;
    }
    right--;
    count -= right / 3;
    // cout << "\tl" << left << 'r' << right << '=' << (left + right) / 3 <<
    // endl;
    count += (left + right) / 3;
  }
  // cout << '\t' << tmp << count << n << endl;
  if (tmp && n >= 3) {

    count = ceil((n + 3 - 1) / 3);
  }
  cout << count;
  // cout << endl << "============";
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
