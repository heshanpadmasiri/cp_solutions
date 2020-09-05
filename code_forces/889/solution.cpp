#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, tmp;
    vector<int> data;
    scanf("%d", &n);
    data.reserve(n);
    int twos = 0;
    int ones = 0;
    while(scanf("%d", &tmp) != EOF){ 
        data.push_back(tmp);
        if(tmp == 1){
            ones++;
        } else {
            twos++;
        }
    }
    int teams = 0;
    if(twos <= ones){
       teams += twos;
       ones -= twos;
       teams += ones/3;
    } else {
       teams = ones;
    }
    cout << teams << endl; 
    return 0;
}
