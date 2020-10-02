#include<bits/stdc++.h>
using namespace std;
#define LEN 200000

int** dp = new int*[4];

int solve(){
    string input;
    cin >> input;
    int max_len = input.length();
    for(int i=0; i<max_len; i++){
        char c = input[i]-'1';
        for(int j=0; j<3; j++){
            dp[j][i] = i>0? dp[j][i-1] : 0;
        }
        dp[c][i]++;
    }
    for(int i=2; i< max_len; i++){
        if(dp[3][i-1] == -1){
            if(dp[0][i] > 0 && dp[1][i] > 0 && dp[2][i] > 0){
                // todo: scan from back
                int j = 0;
                int len = i+1;
                while(j < i){
                    if(((dp[0][i]-dp[0][j]) > 0) && ((dp[1][i]-dp[1][j]) > 0) && ((dp[2][i]-dp[2][j]) > 0)){                            
                        j++;
                        len--;                       
                    } else {
                        break;
                    }
                }
                dp[3][i] = len;
            } else {
                dp[3][i] = -1;
            }
        } else {
            int j = (i - dp[3][i-1])+1;
            if(j>=0){
                int len = dp[3][i-1];
                while(j < i){
                    if(((dp[0][i]-dp[0][j]) > 0) && ((dp[1][i]-dp[1][j]) > 0) && ((dp[2][i]-dp[2][j]) > 0)){                            
                        j++;
                        len--;                       
                    } else {
                        break;
                    }
                }
                dp[3][i] = len;
            } else {
                dp[3][i] = dp[3][i-1];
            }  
        }
    }
    return dp[3][max_len-1] != -1 ? dp[3][max_len-1] : 0;
}
int main(){
    int t;
    for(int i=0; i<4;i++){
        dp[i] = new int[LEN];
    }
    dp[3][0] = -1;
    dp[3][1] = -1;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}