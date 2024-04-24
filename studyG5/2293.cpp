/*
    #2293 동전 1
*/
#include<iostream>
using namespace std;

int n, k, dp[10004];
int main(){
    cin >> n >> k;
    int v;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> v;
        for(int j = v; j <= k; j++){
            dp[j] += dp[j - v];
        }
    }
    cout << dp[k];
    return 0;
}