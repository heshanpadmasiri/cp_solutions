#include <bits/stdc++.h>

using namespace std;

struct IceCream {
  int a, b;
  long long c;
};

int main() {
  int n, k, a, b, c;
  cin >> n >> k;
  vector<IceCream> data;
  data.reserve(n);
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    IceCream ic;
    ic.a = a;
    ic.b = b;
    ic.c = c;
    data.push_back(ic);
  }
  sort(data.begin(), data.end(),
       [](const IceCream &left, const IceCream &right) -> bool {
         return left.c < right.c;
       });
  vector<long long> prefix_arr(n);
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      prefix_arr[i] = data[i].a;
    } else {
      prefix_arr[i] = prefix_arr[i + 1] + data[i].a;
    }
  }
  // for (auto each : prefix_arr) {
  // cout << each << ',';
  //}
  // cout << endl;
  long long cost = 0;
  int remain = k;
  for (int i = 0; i < n; i++) {
    IceCream ic = data[i];
    auto a = ic.a;
    auto b = ic.b;
    auto c = ic.c;
    int take;
    // cout << remain - b << ',' << prefix_arr[i] - a << ',' << remain - a <<
    // endl;
    if ((remain - b) >= 0 && (prefix_arr[i] - a) <= (remain - b)) {
      take = b;
    } else if ((remain - a) >= 0 && (prefix_arr[i] - a) <= (remain - a)) {
      take = remain - (prefix_arr[i] - a);
    } else {
      cout << -1 << endl;
      return 0;
    }
    // if (i == n - 1) {
    // take = remain;
    //}
    cost += take * c;
    remain -= take;
    // cout << '\t' << take << '(' << c << ')' << ',' << remain << ',' << cost
    //<< endl;
  }
  if (remain > 0) {
    cout << -1 << endl;
  } else {

    cout << cost << endl;
  }
  return 0;
}
