#include<iostream>
#include<cstring>

using namespace std;

int t, w, dp[1004][2][34], a[1004];

int solve(int idx, int tree, int cnt){
    if(cnt < 0) return -1e9;
    if(idx == t) return cnt == 0 ? 0 : -1e9;
    int &ret = dp[idx][tree][cnt];
    if(ret != -1) return ret;
    return ret = max(solve(idx + 1, tree^1, cnt - 1), solve(idx + 1, tree, cnt)) + (tree == a[idx] - 1);
}

int main(void){
    cin >> t >> w;
    for(int i = 0; i < t; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << max(solve(0, 0, w), solve(0, 1, w - 1));
    return 0;
}