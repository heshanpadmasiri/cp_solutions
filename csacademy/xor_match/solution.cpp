#include <bits/stdc++.h>

using namespace std;
#define N 1001

int main(){
    int a, b;
    cin >> a >> b;
    bitset<N> A_arr;
    bitset<N> B_arr;
    int tmp;
    bitset<N> mask;
    for(int i = a-1; i >= 0; i--){
        cin >> tmp;
        A_arr[i] =tmp;
        mask[i] = 1;
    }   
    for(int i = b-1; i >= 0; i--){
        cin >> tmp;
        B_arr[i] =tmp;
    }
    int lim = b-a;
    int count = 0;
    for(int i = 0; i <= lim; i++){
        bitset<N> A(A_arr);
        bitset<N> B(B_arr);
        auto mask_A = A << i;
        bitset<N> shift_mask = mask << i;
        auto mask_B = B & shift_mask;
        if((mask_A ^ mask_B) == shift_mask){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
