/*
    #1149 RGB거리
*/
#include<iostream>
using namespace std;

int n, a[1004][1004], dp[1004][1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
    return 0;
}