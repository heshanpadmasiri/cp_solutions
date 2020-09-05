#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int time_left = (4*60) - (k);
    int time = 0;
    for(int i=1; i<=n; i++){
        time += 5*i;
        if(time > time_left){
            cout << i-1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
