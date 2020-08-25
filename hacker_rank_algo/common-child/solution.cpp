#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int len = s1.length();
    int** dp = new int*[len+1];
    for(int i = 0; i < len+1; ++i){
        dp[i] = new int[len+1];
        for (int j = 0; j < len+1; j++)
        {
            dp[i][j] =0;
        }
        
    }


    for (int i = 1; i < len+1; i++)
    {
        char a = s1[i-1];
        for (int j = 1; j < len+1; j++)
        {
            char b = s2[j-1];
            if (a == b)
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+1);
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
            
        }
        
    }
    return dp[len][len];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
