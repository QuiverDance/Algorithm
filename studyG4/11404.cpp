/*
    #11404 플로이드
*/
#include <iostream>
#define INF 1e9
using namespace std;

int n, m, dist[104][104];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    
    int from, to, weight;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> weight;
        if(dist[from][to] > 0) dist[from][to] = min(dist[from][to], weight);
        else dist[from][to] = weight;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
        }
        cout << '\n';
    }
    return 0;
}