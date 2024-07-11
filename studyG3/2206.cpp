/*
    #2206 줄 세우기
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

struct Node{
    pair<int, int> pos;
    bool isBroken;
};

int n, m, a[1004][1004], dist1[1004][1004], dist2[1004][1004], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<Node> q;
void bfs(int sy, int sx, int visited[][1004]){
    q = queue<Node>();
    Node st;
    st.pos = {sy, sx}; st.isBroken = false;
    q.push(st); visited[st.pos.first][st.pos.second] = 1;
    int y, x;
    Node cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        tie(y, x) = cur.pos;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(a[ny][nx] == 1 && cur.isBroken) continue;
            if(visited[ny][nx] && visited[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            Node temp; temp.pos.first = ny; temp.pos.second = nx;
            temp.isBroken = (a[ny][nx] == 0 ? cur.isBroken : true);
            q.push(temp);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
    }
    bfs(0, 0, dist1);
    bfs(n - 1, m - 1, dist2);
    
    if(dist1[n - 1][m - 1] == 0 && dist2[0][0] == 0) cout << -1;
    else{
        if(dist1[n - 1][m - 1] == 0 || dist2[0][0] == 0) cout << max(dist1[n - 1][m - 1], dist2[0][0]);
        else cout << min(dist1[n - 1][m - 1], dist2[0][0]);
    }
    return 0;
}