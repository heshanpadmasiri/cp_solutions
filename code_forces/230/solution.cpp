#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int s,n,x,y;
    cin >> s >> n;
    vector<pii> data;
    data.reserve(n);
    for(int i=0; i<n; i++){
        cin >> x >> y;
        data.push_back(make_pair(x,y));
    } 
    sort(data.begin(), data.end());
    int curr_health = s;
    for(auto each: data){
        int health = each.first;
        int bonus = each.second;
        if(health < curr_health){
            curr_health += bonus;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}