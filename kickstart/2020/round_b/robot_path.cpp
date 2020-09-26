#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define UPPER 1000000000

pair<int, int> repeat_move(int number, string &program, int x, int y) {
  while (number--) {
    for (char const &c : program) {
      if (c == 'W') {
        x--;
      } else if (c == 'E') {
        x++;
      } else if (c == 'N') {
        y--;
      } else {
        y++;
      }
    }
  }
  return {x, y};
}

void solve() {
  string program;
  cin >> program;
  int x, y;
  x = 1;
  y = 1;
  string buffer;
  int number;
  for (char const &c : program) {
    if ((c > '0') && (c <= '9')) {

      cout << c << endl;
      number = c - '0';
    } else {
      if (c == '(') {
        buffer = "";
        continue;
      }
      if (c == ')') {
        auto tmp = repeat_move(number, buffer, x, y);
        x = tmp.first % UPPER;
        y = tmp.second % UPPER;
        continue;
      }
      if (c == 'W') {
        x--;
      } else if (c == 'E') {
        x++;
      } else if (c == 'N') {
        y--;
      } else {
        y++;
      }
    }
  }
  if (x == 0) {
    x = UPPER;
  }
  if (y == 0) {
    y = UPPER;
  }
  cout << x << " " << y;
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
