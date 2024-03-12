/*
    #11048 이동하기
*/
#include<iostream>
#include<cstring>
using namespace std;

int n, m, a[1004][1004], dp[1004][1004];
int solve(int y, int x) {
	if (y >= n || x  >= m)
		return 0;
	int &ret = dp[y][x];
    if(ret >= 0) return ret;
    int f = solve(y, x + 1), s = solve(y + 1, x);
	ret = f > s ? f + a[y][x] : s + a[y][x];
	return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(&dp[0][0], -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    cout << solve(0, 0);
    return 0;
}