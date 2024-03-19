/*
    #1697 숨바꼭질
*/
#include <iostream>
#include <queue>
using namespace std;

int n, k, dp[100004];
queue<int> q;
int main() {
    cin >> n >> k;
    if(k <= n){
        cout << n - k; return 0;
    }
    for(int i = 0; i <= n; i++)
        dp[i] = n - i;
    for(int i = n + 1; i <= k; i++){
        if(i % 2 == 0) dp[i] = dp[i / 2] + 1;
        else
            dp[i] = min(dp[(i - 1) / 2], dp[(i + 1) / 2]) + 2;
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    cout << dp[k];
    return 0;
}