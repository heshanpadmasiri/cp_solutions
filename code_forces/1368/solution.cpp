#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k, i;
  long long count[10] = {0};
  i = 1;
  cin >> k;
  while (pow(i, 10) < k) {
    i++;
  }
  if (pow(i, 10) > k) {
    i--;
  }
  fill(count, count + 10, i);
  long long value = pow(i, 10);
  if (value < k) {
    for (int j = 0; j < 10; j++) {
      count[j]++;
      if (j == 9) {
        value = pow(count[j], 10);
      } else {
        value = pow(count[j], j + 1) * pow(count[j + 1], 9 - j);
      }
      if (value >= k) {
        break;
      }
    }
  }
  string text = "codeforces";
  for (int j = 0; j < 10; j++) {
    long long c = count[j];
    while (c--) {
      cout << text[j];
    }
  }
  cout << endl;
  return 0;
}
