/*
    #1890 점프
*/
#include<iostream>
using namespace std;

typedef long long ll;
ll n, a[104][104], dp[104][104];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] == 0 || (i == n - 1) && (j == n - 1)) continue;
            if(i + a[i][j] < n) dp[i + a[i][j]][j] = dp[i + a[i][j]][j] + dp[i][j];
            if(j + a[i][j] < n) dp[i][j + a[i][j]] = dp[i][j + a[i][j]] + dp[i][j];
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}