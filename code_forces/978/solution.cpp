#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int n, m;
  ll tmp;
  ll tot = 0;
  scanf("%d %d", &n, &m);
  vector<ll> acc_rooms;
  acc_rooms.reserve(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    tot += tmp;
    acc_rooms.push_back(tot);
  }
  int idx = 0;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    while (acc_rooms[idx] < tmp) {
      idx++;
    }
    if (idx == 0) {
      cout << idx + 1 << " " << tmp << endl;
    } else {
      cout << idx + 1 << " " << tmp - acc_rooms[idx - 1] << endl;
    }
  }
}
