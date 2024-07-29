/*
    #11066번 파일 합치기
*/
#include<iostream>
#define INF 1e9
using namespace std;

int t, n, a[504], sum[504], dp[504][504];
int solve(int st, int ed){
    if(st == ed) return 0;
    if(st + 1 == ed) return a[st] + a[ed];

    int& ret = dp[st][ed];
    if(ret != INF) return ret;

    for(int mid = st; mid < ed; mid++){
        int left = solve(st, mid);
        int right = solve(mid + 1, ed);
        ret = min(ret, left + right);
    }
    return ret += sum[ed] - sum[st - 1];
}

int main() {
    cin >> t;
    while(t--){
        fill(&dp[0][0], &dp[0][0] + 504 * 504, INF);
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        cout << solve(1, n) << '\n';
    }
    return 0;
}