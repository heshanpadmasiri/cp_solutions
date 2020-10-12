#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  string u;
  unordered_map<string, int> users;
  cin >> t;
  while (t--) {
    cin >> u;
    if (users.find(u) != users.end()) {
      int val = users[u];
      cout << u << val + 1 << endl;
      users[u] = val + 1;
    } else {
      cout << "OK" << endl;
      users[u] = 0;
    }
  }
  return 0;
}
