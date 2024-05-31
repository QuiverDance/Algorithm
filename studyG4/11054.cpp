/*
    #11054 가장 긴 바이토닉 부분 수열
*/
#include <iostream>
using namespace std;

int n, a[1004], dp[1004][2], ret = 1;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    fill(&dp[0][0], &dp[0][0] + 1004 * 2, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            if(a[i] < a[j]) dp[i][1] = max(dp[i][1], max(dp[j][0] + 1, dp[j][1] + 1));
            ret = max(ret, max(dp[i][0], dp[i][1]));
        }
    }
    cout << ret;
    return 0;
}