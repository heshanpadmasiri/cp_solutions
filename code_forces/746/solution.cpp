#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string input;
    cin >> n >> input;
    string output(input);
    for(int i=0; i < n; i++){
        int len = n-(i);
        int idx = len/2;
        if(len%2 == 0){
            idx--;
        } else {
            idx += i;
        } 
        output[idx] = input[i];
    }
//    string tmp(output);
    cout << output << endl;

    return 0;
}
