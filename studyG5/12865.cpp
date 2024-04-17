/*
    #12865 평범한 배낭
*/
#include<iostream>
using namespace std;

int n, k, dp[100004], w, v;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> w >> v;
        for(int j = k; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[k];
    return 0;
}