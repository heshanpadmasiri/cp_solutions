#include <bits/stdc++.h>

using namespace std;
int main(){
    bitset<10> occupied;
    int t;
    string data;
    cin >> t >> data;
    for(auto &each: data){
        if(each == 'R'){
            for(int i=9; i>-1; i--){
                if(!occupied[i]){
                    occupied[i] = 1;
                    break;
                }
            }
        } else if(each == 'L'){
            for(int i=0; i<10; i++){
                if(!occupied[i]){
                    occupied[i] = 1;
                    break;
                }
            }
        } else {
            int idx = each - '0';
            occupied[idx] = 0;
        }
    }
    auto output = occupied.to_string();
    reverse(output.begin(), output.end());
    cout << output << endl;
    return 0;
}

