#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string a, string b){
   map<char,int> a_count;
   for(auto &c: a){
        if(a_count.find(c) != a_count.end()){
            a_count[c]++;
        } else {
            a_count[c] = 1;
        } 
   }
   for(auto &c : b){
       if(a_count.find(c) == a_count.end() || a_count[c] <= 0){
           return false;
       }
       a_count[c]--;
   }
   for(auto each: a_count){
       if(each.second != 0){
           return false;
       }
   }
   return true;
}

int main(){
    int n;
    cin >> n;
    map<int,list<string>> inputs;
    string tmp;
    while(n--){
        cin >> tmp;
        int len = tmp.length();
        if(inputs.find(len) == inputs.end()){
            list<string> data;
            data.push_back(tmp);
            inputs[len] = data;
        } else {
            inputs[len].push_back(tmp);
        }
    }
    int set_count = 0;
    for(auto each: inputs){
        auto words = each.second;
        while(!words.empty()){
            auto first = words.front();
            int i = words.size();
            words.remove_if([first](string other){return isAnagram(first, other);});
            int diff = i - words.size();
            if(diff > set_count){
                set_count = diff;
            }           
        }
    }
    cout << set_count << endl;
}

