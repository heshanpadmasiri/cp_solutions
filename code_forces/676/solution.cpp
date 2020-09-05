#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,tmp;
    scanf("%d",&n);
    int index[2];
    int j = 0;
    for(int i=0; i<n; i++){
        scanf("%d",&tmp);
        if(tmp == 1 || tmp == n){
            index[j] = i;
            j++;
        }
    }
    if(index[0] == 0 || index[1] == (n-1)){
        cout << n-1 << endl;
        return 0;
    }
    int right = (n-1) - index[0];
    int left = index[1] - 0;
    cout << max(right, left) << endl;
    return 0;
}
