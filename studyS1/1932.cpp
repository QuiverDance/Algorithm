/*
    #1932 정수 삼각형
*/
#include<iostream>
using namespace std;

int n, a[504][504], dp[504][504], ret;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i - 1][0] + a[i][0];
        for(int j = 1; j < i; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + a[i][i];
    }
    for(int i = 0; i <= n; i++){
        ret = max(ret, dp[n][i]);
    }
    cout << ret;
    return 0;
}