#include <bits/stdc++.h>

using namespace std;

int main() {
  string tmp;
  string data[2];
  cin >> tmp;
  data[0] = tmp;
  int n = tmp.length();
  cin >> tmp;
  data[1] = tmp;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (data[0][i] == '0' && data[1][i] == '0') {
      if (i != 0) {
        if (data[0][i - 1] == '0') {
          data[0][i - 1] = '1';
          data[0][i] = '1';
          data[1][i] = '1';
          count++;
          continue;
        } else if (data[1][i - 1] == '0') {
          data[1][i - 1] = '1';
          data[0][i] = '1';
          data[1][i] = '1';
          count++;
          continue;
        }
      }
      if (i != n - 1) {
        if (data[0][i + 1] == '0') {
          data[0][i + 1] = '1';
          data[0][i] = '1';
          data[1][i] = '1';
          count++;
          continue;
        } else if (data[1][i + 1] == '0') {
          data[1][i + 1] = '1';
          data[0][i] = '1';
          data[1][i] = '1';
          count++;
          continue;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}
