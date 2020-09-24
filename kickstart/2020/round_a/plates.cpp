#include <bits/stdc++.h>
using namespace std;
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int solve(){
    int n,k,p,tmp;
    cin >> n >> k >> p;
    int** dp = new int*[n];
    int** plates = new int*[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[p+1];
        plates[i] = new int[k+1];
        plates[i][0] = 0;
        for(int j=1; j < k+1; j++){
            cin >> tmp;
            plates[i][j] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    
    for (int i = 1; i < p+1; i++)
    {
        if(i <= k){
            int tot = 0;
            for(int j=1; j <= i ; j++){
                tot += plates[0][j];
            }
            dp[0][i] = tot;
        } else {
            dp[0][i] = dp[0][i-1];
        }
    }

    for(int i = 1; i < n; i++){ //stacks
        for(int j = 1; j < p+1; j++){ // plates
            int tot = 0;
            int m = 0;
            for(int x=0; x <=j; x++){
                if(x > k){
                    m = max(m , dp[i-1][j-x]+tot);
                } else {
                    tot += plates[i][x];
                    m = max(m , dp[i-1][j-x]+tot);
                }
                
            }
            dp[i][j] = m;
        }
    }
    
    return dp[n-1][p];
}

int main(){
    _fast_;
    int t;
    cin >> t;
    int i = 1;
    while(t--){
        cout << "Case #" << i << ": " << solve() << endl;
        i += 1;
    }
    return 0;
}