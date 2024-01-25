/*
#11727 2*n 타일링(2)
*/
#include<iostream>
using namespace std;

int n, dp[1004];
int main(){
    cin >> n;
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }
    cout << dp[n];
    return 0;
}