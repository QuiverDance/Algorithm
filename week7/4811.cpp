#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;
ll n, dp[34][34];

ll solve(int idx, int w, int h){
    if(w < 0 || h < 0) return 0;
    if(idx == 2 * n) return 1;
    ll &ret = dp[w][h];
    if(ret != -1) return ret;
    return ret = solve(idx + 1, w - 1, h + 1) + solve(idx + 1, w, h - 1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    while(n != 0){
        cout << solve(0, n, 0) << '\n';
        cin >> n;
    }
    return 0;
}