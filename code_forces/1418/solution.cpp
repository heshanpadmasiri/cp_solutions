#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, tmp,c,ans;
    cin >> n;
    vector<int> segments; 
    c=0;
    ans=0;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(i==0 && tmp==1){
            ans++;
            continue;
        }
        if(tmp==1){
            c++;
        } else {
            if(c>0){
                segments.push_back(c);
            }
            c = 0;
        }
    }
    if(c>0){
        segments.push_back(c);
    }



    for(auto each: segments){
        ans += each/3;
    }
    cout <<ans<< endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}