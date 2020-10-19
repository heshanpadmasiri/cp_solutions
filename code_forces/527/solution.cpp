#include <bits/stdc++.h>

using namespace std;
typedef pair<char, int> op;
int main() {
  int w, h, n, i;
  char a;
  scanf("%d %d %d\n", &w, &h, &n);
  stack<op> operations;
  set<int> horizontal;
  set<int> vertical;
  horizontal.insert(0);
  horizontal.insert(w);
  vertical.insert(0);
  vertical.insert(h);
  while (n--) {
    scanf("%c %d\n", &a, &i);
    operations.push(make_pair(a, i));
    if (a == 'V') {
      horizontal.insert(i);
    } else {
      vertical.insert(i);
    }
  }
  stack<long long> answers;
  // find the largest horizontal segment;
  int max_h = 0;
  int last = 0;
  for (auto each : horizontal) {
    int seg_len = each - last;
    max_h = max(seg_len, max_h);
    last = each;
  }

  // find the largest vertical segment;
  int max_v = 0;
  last = 0;
  for (auto each : vertical) {
    int seg_len = each - last;
    max_v = max(seg_len, max_v);
    last = each;
  }
  long long ans = (long long)max_h * (long long)max_v;
  answers.push(ans);
  while (operations.size() > 1) {
    auto o = operations.top();
    operations.pop();
    set<int>::iterator it;
    if (o.first == 'V') {
      it = horizontal.find(o.second);
    } else {
      it = vertical.find(o.second);
    }
    int left = *prev(it);
    int right = *next(it);
    int new_seg = right - left;
    if (o.first == 'V') {
      max_h = max(new_seg, max_h);
      horizontal.erase(it);
    } else {
      max_v = max(new_seg, max_v);
      vertical.erase(it);
    }
    ans = (long long)max_h * (long long)max_v;
    answers.push(ans);
  }
  while (!answers.empty()) {
    ans = answers.top();
    answers.pop();
    cout << ans << endl;
  }
  return 0;
}
