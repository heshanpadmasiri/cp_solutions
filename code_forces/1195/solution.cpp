#include <bits/stdc++.h>

#define BASE 998244353

using namespace std;

typedef long long ll;

map<ll, ll> pow_map;

ll get_power(ll i) {
  if (pow_map.find(i) == pow_map.end()) {
    if (i == 0) {
      pow_map[0] = 1;
    } else {
      ll val = 10;
      ll idx = log2(i);
      ll diff = i - (1 << idx);
      // cout << idx << ':' << diff << ":";
      while (idx--) {
        val *= val % BASE;
      }
      val %= BASE;
      if (diff) {
        // cout << "**" << get_power(diff) << "," << val << "**";
        val *= get_power(diff) % BASE;
      }
      val %= BASE;
      pow_map[i] = val % BASE;
      // cout << i << ',' << pow_map[i] << endl;
    }
  }
  return pow_map[i];
}

int main() {
  int n;
  string tmp;
  vector<string> a;
  scanf("%d", &n);
  a.reserve(n);
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }
  int len = log10(stoi(a[0])) + 1;
  vector<ll> type1;
  type1.reserve(n);
  int upper = 2 * (len - 1) + 1;
  for (auto each : a) {
    ll val = 0;
    int idx = len - 1;
    for (ll j = 1; j <= upper; j += 2) {
      int id_v = each[idx] - '0';
      ll a = (get_power(j) * (id_v % BASE)) % BASE;
      // cout << a << ',' << id_v << ',' << get_power(j) << endl;
      val += a % BASE;
      idx--;
    }
    val %= BASE;
    // cout << "+++++++++++" << endl;

    type1.push_back(val);
  }
  upper = 2 * (len - 1);
  ll type2_sum = 0;
  for (auto each : a) {
    ll val = 0;
    int idx = len - 1;
    for (ll j = 0; j <= upper; j += 2) {
      int id_v = each[idx] - '0';
      ll a = (get_power(j) * (id_v % BASE)) % BASE;
      // cout << a << ',' << id_v << ',' << pow(10, j) << endl;
      val += a % BASE;
      idx--;
    }
    // cout << "+++++++++++" << endl;
    type2_sum += val % BASE;
  }
  type2_sum %= BASE;
  ll ans = 0;
  for (auto each : type1) {
    ans += ((each * n) + type2_sum) % BASE;
  }
  ans %= BASE;
  cout << ans << endl;
  return 0;
}
