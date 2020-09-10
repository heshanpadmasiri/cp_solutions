#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cin >> input;
    char output[210];
    set<char> vovels = {'a','e','i','o','u','y'};
    int idx = 0;
    for(char const &c: input){
        auto val = tolower(c);
        if(vovels.find(val) != vovels.end()){
            continue;
        }
        output[idx] = '.';
        output[idx+1] = val;
        idx += 2;
    }
    output[idx] = '\0'; 
    string os(output);
    cout << os << endl;
    return 0;
}
