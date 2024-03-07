/*
    #11722 가장 긴 감소하는 부분 수열
*/
#include<iostream>
using namespace std;

int n, a[1004], dp[1004], ret;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(a[i] < a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ret = max(ret, dp[i]);
    }
    cout << ret;
    return 0;
}