/*
    #16194 카드 구매하기 2
*/
#include<iostream>
using namespace std;

int n, a[10004], dp[10004];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = i; j <= n; j++){
            if(dp[j] == 0) dp[j] = dp[j - i] + a[i];
            else dp[j] = min(dp[j], dp[j - i] + a[i]);
        }
    }
    cout << dp[n];
    return 0;
}