#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
char s[N];
int sum[N];
int n;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;

    cin >> s + 1;

    for (int i = 1; i <= n; i++)
      a[i] = s[i] - '0', sum[i] = sum[i - 1] + a[i];

    unordered_map<int, int> mp;
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
      int s = sum[i - 1] - i + 1;
      mp[s]++;
      ans += mp[sum[i] - i];
    }

    cout << ans << endl;
  }
  // system("pause");
}
