#include<iostream>
#include<cstring>

#define INF 1e9

using namespace std;

int n, dp[16][1 << 16], dist[16][16];

int tsp(int idx, int visited){
    if(visited == (1 << n) - 1){
        return dist[idx][0] ? dist[idx][0] : INF;
    }
    int &ret = dp[idx][visited];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < n; i++){
        if(visited & (1 << i)) continue;
        if(dist[idx][i] == 0) continue;
        ret = min(ret, tsp(i, visited | (1 << i)) + dist[idx][i]);
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> dist[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1);
    return 0;
}