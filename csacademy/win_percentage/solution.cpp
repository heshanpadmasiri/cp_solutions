
#include <bits/stdc++.h>

using namespace std;

int get_lower(int g, int p){
    float percentage = p / 100.0;
    float tmp = floor(percentage * g);
    return max(static_cast<int>(tmp), 1);
}

int get_upper(int g, int p){
    float percentage = (p / 100.0) + 0.01;
    float tmp = percentage * g;
    int val = static_cast<int>(tmp);
    if(val != tmp){
        return val;
    } else {
        return val - 1;
    }
}

int main(){
    int g_1, p_1, g_2, p_2;
    cin >> g_1 >> p_1 >> g_2 >> p_2;
    int lower = get_lower(g_1, p_1);
    int upper = get_upper(g_2, p_2);
    cout << upper - lower << endl;
}
