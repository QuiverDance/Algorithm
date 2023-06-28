#include<iostream>
#include<cstring>

using namespace std;

int n, d[24], h[24], dp[104];

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++){
        for(int j = 100; j > d[i]; j--)
            dp[j] = max(dp[j], dp[j - d[i]] + h[i]);
    }
    cout << dp[100];
    return 0;
}