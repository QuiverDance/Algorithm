/*
    #1309 동물원
*/
#include<iostream>
using namespace std;

int n, dp[100004][3];
int main(){
    cin >> n;
    if(n == 1){
        cout << 3; return 0;
    }
    dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 1;
    for(int i = 1; i < n; i++){
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 9901;
    return 0;
}