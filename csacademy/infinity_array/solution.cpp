#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> type0;
    vector<vector<int>> type1;
    int l, r, type, w;
    for(int i=0; i < m; i++){
        cin >> l >> r >> type >> w;
        vector<int> tmp;
        tmp.reserve(3);
        tmp.push_back(l);
        tmp.push_back(r);
        tmp.push_back(w);
        if(type == 0){
            type0.push_back(tmp);
        } else {
            type1.push_back(tmp);
        }
    }
    vector<int> type0_count(n,0);
    long long upper_bound = 0;
    vector<long long> upper_bounds;
    vector<int> type1_count(n,0);
    long long lower_bound = 0;
    vector<long long> lower_bounds;
    for(auto each: type0){
        l = each[0];
        r = each[1];
        w = each[2];
        int head = n - (l%n);
        int tail = (r%n) + 1;
        for(int i=(l%n); i < n; i++){
            type0_count[i] += 1;
        }
        for(int i=0; i < tail; i++){
            type0_count[i] += 1;
        }
        int remainder = ((r-l+1) - (head+tail)) / n;
        
        for(int i=0; i < n; i++){
            type0_count[i] += remainder;
        }
        upper_bound += w;
        if(remainder > 0){
            upper_bounds.push_back(w/remainder);
        }
    }
    auto count = *min_element(type0_count.begin(), type0_count.end());
    if(count == 0){
        cout << "-1" << endl;
        return 0;
    } else {
        
        upper_bound /= count;
        upper_bound = min(upper_bound, *min_element(upper_bounds.begin(), upper_bounds.end()));
        for(auto each: type1){
            l = each[0];
            r = each[1];
            w = each[2];
            int head = n - (l%n);
            int tail = (r%n) + 1;
            for(int i=(l%n); i < n; i++){
                type1_count[i] += 1;
            }
            for(int i=0; i < tail; i++){
                type1_count[i] += 1;
            }
            int remainder = ((r-l+1) - (head+tail)) / n;
        cout << head << "," << tail << "," << remainder << endl;
        cout << "**" << remainder<< endl;
            for(int i=0; i < n; i++){
                type1_count[i] += remainder;
            }
            lower_bound += w;
            if(remainder > 0){
                lower_bounds.push_back(w/(remainder+1));
            }
        }
        count = *min_element(type1_count.begin(), type1_count.end());
        if(count == 0){
            cout << upper_bound << endl;
        } else {
            lower_bound /= (count+1);
            for(auto each : lower_bounds){
                cout << each << endl;
            }
            cout << lower_bound << endl;
            lower_bound = max(lower_bound, *max_element(lower_bounds.begin(), lower_bounds.end()));
            cout << upper_bound << ',' << lower_bound << endl;
            cout << upper_bound - lower_bound << endl;
        }
    }
}

