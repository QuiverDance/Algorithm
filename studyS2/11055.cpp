/*
    #11055 가장 큰 증가하는 부분수열
*/
#include<iostream>
using namespace std;

int n, a[1004], dp[1004], ret;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    ret = a[0];
    for(int i = 0; i < n; i++){
        dp[i] = a[i];
        for(int j = i - 1; j >= 0; j--){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ret = max(ret, dp[i]);
    }
    cout << ret;
    return 0;
}