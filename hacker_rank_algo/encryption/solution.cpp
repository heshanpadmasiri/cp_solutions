#include<cstdio>
#include<string.h>
#include<iostream>
#include<cmath>
#include<vector>
#include <numeric>    

using namespace std;

char inputString[90];

void solve(){
    int s = strlen(inputString);
    float sq = sqrt(s);
    int row = floor(sq);
    int columns = ceil(sq);

    vector<string> output(columns,"");
    int col = 0;
    for(int i=0; i < s; i++){
        if(i%columns == 0){
            col = 0;
        }
        output[col].push_back(inputString[i]);

        col++;
    }

    cout << accumulate(output.begin(), output.end(), string(), [](string &ss, string &s){
        return ss.empty() ? s: ss + " " + s;
    });

    // std::accumulate(std::begin(x), std::end(x), string(),
    //                             [](string &ss, string &s)
    //                             {
    //                                 return ss.empty() ? s : ss + "," + s;
    //                             });
    // for (auto each : output)
    // {
    //     cout << each << endl;
    // }
    
}

int main(){
    char in[90];
    strcpy (inputString,"");
    while(scanf("%s", in) != EOF){
        strcat(inputString, in);
    }
    solve();
    return 0;
}
