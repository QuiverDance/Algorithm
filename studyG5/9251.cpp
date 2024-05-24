/*
    #9251 LCS
*/
#include<iostream>
#include<string>
using namespace std;

int dp[1004][1004], ret;
string s1, s2;
int main(){
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret;
    return 0;
}