#include <bits/stdc++.h>
using namespace std;
#define _fast_                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)

typedef pair<int, int> pi;

set<pi> blocked;
vector<pi> get_neighbours(pi current, int s) {
  int i = current.first;
  int j = current.second;
  vector<pi> neighbours;
  if (j % 2 == 0) {
    if (j - 1 > 0) {
      neighbours.push_back(make_pair(i, j - 1));
      if (i - 1 > 0) {
        neighbours.push_back(make_pair(i - 1, j - 1));
      }
    }
    if (j + 1 <= (2 * i - 1)) {
      neighbours.push_back(make_pair(i, j + 1));
    }
  } else {
    if (j - 1 > 0) {
      neighbours.push_back(make_pair(i, j - 1));
    }
    if (j + 1 <= (2 * i - 1)) {
      neighbours.push_back(make_pair(i, j + 1));
    }
    if (j + 1 <= s && i + 1 <= s) {
      neighbours.push_back(make_pair(i + 1, j + 1));
    }
  }
  vector<pi> tmp;
  for (auto each : neighbours) {
    if (blocked.find(each) == blocked.end()) {
      tmp.push_back(each);
    }
  }
  return tmp;
}

int solve() {
  int s, r_a, p_a, r_b, p_b, c, a, b;
  blocked = set<pi>();
  cin >> s >> r_a >> p_a >> r_b >> p_b >> c;
  for (int i = 0; i < c; i++) {
    cin >> a >> b;
    blocked.insert(make_pair(a, b));
  }
  blocked.insert(make_pair(r_a, p_a));
  blocked.insert(make_pair(r_b, p_b));
  int a_count, b_count;
  a_count = 0;
  b_count = 0;
  auto current = make_pair(r_a, p_a);
  auto next = get_neighbours(current, s);
  while (next.size() > 0) {
    current = next[0];
    blocked.insert(current);
    next = get_neighbours(current, s);
    a_count++;
  }
  current = make_pair(r_b, p_b);
  next = get_neighbours(current, s);
  while (next.size() > 0) {
    current = next[0];
    blocked.insert(current);
    next = get_neighbours(current, s);
    b_count++;
  }
  return a_count - b_count;
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
