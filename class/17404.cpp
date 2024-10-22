/*
    #17404 RGB거리 2
*/
#include<iostream>
using namespace std;

int n, a[1004][3], dp[1004][3], ret = 1e9;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cin >> a[i][j];
    }
    for(int st = 0; st < 3; st++){
        for(int i = 0; i < 3; i++){
            if(st == i) dp[0][i] = a[0][i];
            else dp[0][i] = 1e9;
        }
        for(int i = 1; i < n; i++){
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
        }
        for(int ed = 0; ed < 3; ed++){
            if(st == ed) continue;
            ret = min(ret, dp[n - 1][ed]);
        }
    }
    cout << ret;
    return 0;
}