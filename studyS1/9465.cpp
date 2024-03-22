/*
    #9465 스티커
*/
#include<iostream>
#include<cstring>
using namespace std;

int t, n, dp[100004][3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++) cin >> dp[j][i];
        }
        
        for(int i = 1; i < n; i++){
            dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] += max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        }
        cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << '\n';
    }
    return 0;
}