#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n,p,k,tmp;
    vector<long long> value;
    vector<long long> p_value;
    cin >> n >> p >> k;
    value.reserve(n);
    p_value.reserve(n);
    long long curr_sum = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> tmp;
        value.push_back(tmp);
    }
    sort(value.begin(), value.end());
    for (long long i = 0; i < n; i++)
    {
        curr_sum += value[i];
        p_value.push_back(curr_sum);
    }
    long long lb = upper_bound(value.begin(), value.end(), p) - value.begin();
    lb--;
    if(lb < 0){
        cout << 0;
        return;
    }
    if(lb+1 < k){
        // long long lb_new = lower_bound(p_value.begin(), p_value.end(), p) - p_value.begin();
        // if(p_value[lb_new] > p){
        //     lb_new--;
        // }
        // cout << lb_new+1;
        long long cnt = 0;
        long long cost = 0;
        int idx = 0;
        while(cost < p){
            cost += value[idx];
            idx++;
            cnt++;
        }
        if(cost > p){
            cnt--;
        }
        cout << cnt;
    } else {
        long long cnt = 0;
        long long no_promo = 0;
        long long cost = 0;
        do
        {
            long long left = no_promo-1;
            if(left < 0){
                cost = value[left+k];
            } else {
                cost = p_value[left] + value[left+k];
            }
            if(cost <= p){
                cnt = no_promo + k;
            }
            no_promo++;
        } while (cost <= p && cnt < n);
        cout << cnt;
    }
}

int main(){
    long long t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}