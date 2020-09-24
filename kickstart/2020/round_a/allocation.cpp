#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& prices, int b){
    sort(prices.begin(), prices.end());
    int remainig = b;
    int idx = 0;
    int count = 0;
    while (remainig > 0)
    {
        if(prices[idx] <= remainig){
            count++;
            remainig -= prices[idx];
            idx++;            
        } else {
            break;
        }
    }
    return count;
}

int main(){
    int t,n,b,tmp,c=1;
    cin >> t;
    while (t--)
    {
        cin >> n >> b;
        vector<int> prices;
        prices.reserve(n);
        while (n--)
        {
            cin >> tmp;
            prices.push_back(tmp);
        }
        int solution = solve(prices, b);
        printf("Case #%d: %d",c, solution);
        if(t){
            printf("\n");
        }
        c++;
    }
}
