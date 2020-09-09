#include <bits/stdc++.h>

using namespace std;

bool is_solution(int a, int b, int c){
    if((b-a) > 2 || (c-b) > 2 || (c-a) > 2){
        return false;
    } 
    return true;
}

int main(){
    int n, tmp;
    scanf("%d", &n);
    set<int> balls;
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        balls.insert(tmp);
    }
    vector<int> unique_balls(balls.begin(), balls.end());
    if(unique_balls.size() < 3){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0; i<(unique_balls.size()-2);i++){
        if(is_solution(unique_balls[i], unique_balls[i+1], unique_balls[i+2])){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
