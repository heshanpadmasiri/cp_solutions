#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> deg, used;
vector<pair<int, int>> ans;

mt19937 rnd(time(NULL));

void bfs(int s) {
  used = vector<int>(n);
  used[s] = 1;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto to : g[v]) {
      if (used[to])
        continue;
      if (rnd() & 1)
        ans.push_back(make_pair(v, to));
      else
        ans.push_back(make_pair(to, v));
      used[to] = 1;
      q.push(to);
    }
  }
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

  cin >> n >> m;
  g = vector<vector<int>>(n);
  deg = vector<int>(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
    ++deg[x];
    ++deg[y];
  }

  int pos = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[pos] < deg[i]) {
      pos = i;
    }
  }

  bfs(pos);
  shuffle(ans.begin(), ans.end(), rnd);
  for (auto it : ans)
    cout << it.first + 1 << " " << it.second + 1 << endl;

  return 0;
}
