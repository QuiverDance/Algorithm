/*
    #11052 카드 구매하기
*/
#include<iostream>
using namespace std;

int n, p, dp[1004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p;
        for(int j = i; j <= n; j++)
            dp[j] = max(dp[j], dp[j - i] + p);
    }
    cout << dp[n];
    return 0;
}