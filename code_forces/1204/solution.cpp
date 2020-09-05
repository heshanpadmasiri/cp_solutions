#include <bits/stdc++.h>

using namespace std;

int highest(int n, int l, int r){
    int shift_point = n - (n-r);
    int total = 0;
    int last = 1;
    for(int i=0; i<n; i++){
        if(i < shift_point-1){
            total += last;
            last *= 2;
        } else {
            total += last;
        }
    } 
    return total;
}

int lowest(int n, int l, int r){
    int shift_point = n-l;
    int total = 0;
    int last = 1;
    for(int i=0; i<n; i++){
        if(i < shift_point){
            total += 1;
        } else {
            total += last;
            last *= 2;
        }
    } 
    return total;
}

int main(){
    int n,l,r;
    scanf("%d %d %d", &n, &l, &r);
    auto low = lowest(n, l, r);
    auto high = highest(n, l, r);
    cout << low << " " << high << endl;
    return 0;
}
