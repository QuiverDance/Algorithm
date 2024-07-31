/*
    #11049 행렬 곱셈 순서
*/
#include<iostream>
#define INF 1 << 31 - 1
using namespace std;

int n, dp[504][504];
pair<int, int> a[504];
int solve(int st, int ed){
    if(st == ed) return 0;
    if(st + 1 == ed) return a[st].first * a[st].second * a[ed].second;

    int &ret = dp[st][ed];
    if(ret != INF) return ret;

    for(int mid = st; mid < ed; mid++){
        int left = solve(st, mid);
        int right = solve(mid + 1, ed);
        ret = min(ret, left + right + a[st].first * a[mid].second * a[ed].second);
    }
    return ret;
}

int main(){
    fill(&dp[0][0], &dp[0][0] + 504 * 504, INF);
    cin >> n;
    int r, c;
    for(int i = 1; i <= n; i++){
        cin >> r >> c;
        a[i] = {r, c};
    }
    cout << solve(1, n);
    return 0;
}