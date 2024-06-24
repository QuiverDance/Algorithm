/*
    #1976 여행 가자
*/
#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

int n, m, adj[204][204];
vector<int> v;
int main(){
    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num == 0) adj[i][j] = INF;
            else adj[i][j] = 1;
            if(i == j) adj[i][j] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> num;
        v.push_back(--num);
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int cur = v[0], flag = 1;
    for(int i = 1; i < m; i++){
        int next = v[i];
        if(adj[cur][next] == INF){
            flag = 0; break;
        }
        cur = next;
    }
    cout << (flag == 1 ? "YES" : "NO");
    return 0;
}