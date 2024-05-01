/*
    #13549 숨바꼭질3
*/
#include <iostream>
using namespace std;

int dp[100004], n, k;
int main() {
    cin >> n >> k;
    for(int i = 0; i <= n; i++) dp[i] = n - i;
    for(int i = n + 1; i <= k; i++){
        if(i % 2 == 0) dp[i] = dp[i / 2];
        else dp[i] = min(dp[(i - 1) / 2] + 1, dp[(i + 1) / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    cout << dp[k];
    return 0;
}