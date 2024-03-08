/*
    #1699 제곱수의 합
*/
#include<iostream>
using namespace std;

int n, dp[100004], k = 1;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        dp[i] = 1e9;
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}