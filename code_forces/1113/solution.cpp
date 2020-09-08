#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,v;
    scanf("%d %d", &n, &v);
    if(v >= n-1){
        cout << n-1 << endl;
        return 0;
    } else {
        int cost = v;
        int left = n-v-1;
        int i = 2;
        while(left > 0){
            cost += i;
            left--;
            i++;
        } 
        cout << cost << endl;
        return 0;
    }
}
