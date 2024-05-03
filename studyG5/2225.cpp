/*
    #2225 합분해
*/
#include<iostream>
#define DIV 1000000000
using namespace std;

int n, k, dp[204][204];
/*first solution*/
int solve(int num, int len){
    if(len == 1) return 1;
    int &ret = dp[num][len];
    if(ret > 0) return ret;

    ret = 0;
    for(int i = 0; i <= num; i++){
        ret += solve(num - i, len - 1);
        ret %= DIV;
    }
    return ret;
}

int main(){
    cin >> n >> k;
    // cout << solve(n, k);
    
    /*second solution*/
    for(int i = 0; i <= n; i++) dp[1][i] = 1;
    for(int i = 2; i <= k; i++){
        for(int j = 0; j <= n; j++)
            for(int l = 0; l <= j; l++){
                dp[i][j] += dp[i - 1][l];
                dp[i][j] %= DIV;
            }
    }
    cout << dp[k][n];
    return 0;
}