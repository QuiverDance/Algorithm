/*
    #7579 앱
*/
#include<iostream>
using namespace std;

int n, m, dp[10000], w[104], v[104], sum;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> w[i];
        sum += w[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    for(int i = 0; i <= sum; i++){
        if(dp[i] >= m){
            cout << i;
            break;
        }
    }
    return 0;
}