/*
    #14938 서강그라운드
*/
#include<iostream>
using namespace std;

int n, m, r, a[104], ret;
int dist[104][104];
int main(){
    fill(&dist[0][0], &dist[0][0] + 104 * 104, 1e9);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int from, to, t;
    for(int i = 0; i < r; i++){
        cin >> from >> to >> t;
        dist[from][to] = t;
        dist[to][from] = t;
    }
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(dist[i][j] <= m) sum += a[j];
        }
        ret = max(ret, sum);
    }
    cout << ret;
    return 0;
}