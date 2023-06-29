#include<iostream>

using namespace std;

int n, dp[1000004];

void trace(int here){
    if(here == 0) return;
    cout << here << " ";
    if(here % 3 == 0 && dp[here] == dp[here / 3] + 1) trace(here / 3);
    else if(here % 2 == 0 && dp[here] == dp[here / 2] + 1) trace(here / 2);
    else if(here - 1 >= 0 && dp[here] == dp[here - 1] + 1) trace(here - 1);
}

int main(void){
    fill(dp, dp + 1000004, 1e9);
    cin >> n;
    dp[1] = 0;
    for(int i = 1; i <= n; i++){
        if(!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
        if(!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    cout << dp[n] << '\n';
    trace(n);
    return 0;
}