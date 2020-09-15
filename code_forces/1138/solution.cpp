#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, tmp;
    vector<int> data;
    cin >> n;
    data.reserve(n);
    for(int i=0 ; i < n; i++){
        cin >> tmp;
        data.push_back(tmp);
    }
    vector<int> segments;
    int length=0;
    int type=data[0];
    for(int i=0; i<n; i++){
        if(data[i] != type){
            segments.push_back(length);
            type=data[i];
            length=1;
        } else {
            length++;
        }
    }
    segments.push_back(length);
    int max_len=0;
    for(int i=0; i<segments.size()-1; i++){
        int a = segments[i];
        int b = segments[i+1];
        int len = min(a,b)*2;
        max_len = max(len,max_len);
    }
    cout << max_len << endl;
    return 0;
}
