#include<iostream>
#include<cstring>

using namespace std;

int n, k, dp[104][100004];
pair<int, int> a[104], b[104];

int solve(int idx, int _time){
    if(idx == n) return 0;
    int &ret = dp[idx][_time];
    if(ret != -1) return ret;
    ret = -1e9;
    if(_time - a[idx].first >= 0) ret = max(ret, solve(idx + 1, _time - a[idx].first) + a[idx].second);
    if(_time - b[idx].first >= 0) ret = max(ret, solve(idx + 1, _time - b[idx].first) + b[idx].second);
    return ret;
}

int main(void){
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }
    cout << solve(0, k);
    return 0;
}