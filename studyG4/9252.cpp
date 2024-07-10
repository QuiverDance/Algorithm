/*
    #9252 LCS2
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[1004][1004], ret;
string s1, s2, s_ret;
void trace(int y, int x){
    if(y == 0 && x == 0) return;
    if(y - 1 >= 0 && dp[y][x] == dp[y - 1][x]) trace(y - 1, x);
    else if(x - 1 >= 0 && dp[y][x] == dp[y][x - 1]) trace(y, x - 1);
    else{
        s_ret += s1[y - 1];
        trace(y - 1, x - 1);
    }
}
int main(){
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            ret = max(ret, dp[i][j]);
        }
    }
    trace(s1.length(), s2.length());
    reverse(s_ret.begin(), s_ret.end());
    cout << ret << '\n';
    cout << s_ret;
    return 0;
}