#include<iostream>
#include<cstring>

using namespace std;

int n, k, dp[100004], w, v;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int s, t;
    for(int i = 0; i < n; i++){
        cin >> w >> v;
        for(int j = k; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[k];
    return 0;
}