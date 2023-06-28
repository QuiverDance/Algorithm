#include<iostream>
#include<cstring>

using namespace std;

int n, m, dp[10004];
pair<int, int> a[5004];

int solve(int m){
    if(m < 0) return -1e9;
    int &ret = dp[m];
    if(ret != -1) return ret;
    for(int i = 0; i < n; i++)
        ret = max(ret, solve(m - a[i].second) + a[i].first);
    return ret;
}

int main(void){
    double t;
    int s;
    cin >> n >> t;
    while(n != 0){
        memset(dp, -1, sizeof(dp));
        m = (int)(t * 100 + 0.5);
        for(int i = 0; i < n; i++){
            cin >> s >> t;
            a[i] = {s, (int)(t * 100 + 0.5)};
        }
        cout << solve(m) + 1 << '\n';
        cin >> n >> t;
    }
    return 0;
}