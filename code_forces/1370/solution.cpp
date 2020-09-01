#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    int a,b;
    if(n%2 == 0){
        a = n;
        b = n/2;
    } else {
        a = n-1;
        b = (n-1)/2;
    } 
    for(int i = b; i > 0; i--){
        if(b%i==0 && a%i==0){
            cout << i << endl;
            return;
        }
    }
}

int main(){
     int t, tmp;
     cin >> t;
     while(t--){
       cin >> tmp;
       solve(tmp);
     } 
}
