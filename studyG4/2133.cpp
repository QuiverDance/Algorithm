/*
    #2133 타일 채우기
*/
#include<iostream>
using namespace std;

int n, dp[34];
int main(){
    cin >> n;
    dp[2] = 3;
    if(n % 2 == 0){
        for(int i = 4; i <= n; i += 2){
            dp[i] = dp[i - 2] * 3 + 2;
            for(int j = 4; j <= i - 2; j += 2){
                dp[i] += dp[i - j] * 2;
            }
        }
    }
    cout << dp[n];
    return 0;
}