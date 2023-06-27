#include<iostream>
#include<cstring>
#define INF 1e9

using namespace std;

int n, k, dp[10004], temp;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n >> k; 
    fill(dp, dp + 10001, INF);
    dp[0] = 0; 
    
    for(int i = 0; i < n; i++){
        cin >> temp; 
        for(int j = temp; j <= k; j++){
            dp[j] = min(dp[j], dp[j - temp] + 1);
        }
    }
    if(dp[k] == INF) cout << -1 << "\n"; 
    else cout << dp[k] << "\n"; 
    return 0;
}