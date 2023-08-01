#include <iostream>
using namespace std;

int t, n, m, dp[34][34];

void combination(){
    for(int i = 0; i < 31; i++){
        dp[i][0] = 1;
        dp[i][i] = 1; 
        for(int j = 1; j < i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        } 
    }
}

int main(void) {
    cin >> t;
    combination();
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
    return 0;
}