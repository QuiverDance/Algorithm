/*
    #3055번 탈출
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int r, c, ret, visited[54][54], w_visited[54][54], flag;
int sy, sx, ey, ex;
char a[54][54];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q, w_q;
int main(){
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %1c", &a[i][j]);
            if(a[i][j] == 'S'){ 
                sy = i; sx = j;
                q.push({i, j});
                visited[i][j] = 1;
            }
            else if(a[i][j] == 'D'){ ey = i; ex = j;}
            else if(a[i][j] == '*'){
                w_q.push({i, j});
                w_visited[i][j] = 1;
            }
        }
    }

    int y, x, depth = 1;
    while(true){
        while(!w_q.empty()){
            tie(y, x) = w_q.front();
            if(w_visited[y][x] > depth) break;
            w_q.pop();
            for(int d = 0; d < 4; d++){
                int ny = y + dy[d], nx = x + dx[d];
                if(ny < 0 || nx < 0 || ny >= r || nx >= c || w_visited[ny][nx]) continue;
                if(a[ny][nx] == '.'){
                    w_q.push({ny, nx});
                    w_visited[ny][nx] = w_visited[y][x] + 1;
                    a[ny][nx] = '*';
                }
            }
        }
        while(!q.empty()){
            tie(y, x) = q.front();
            if(visited[y][x] > depth) break;
            q.pop();
            for(int d = 0; d < 4; d++){
                int ny = y + dy[d], nx = x + dx[d];
                if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
                if(a[ny][nx] == '.' || a[ny][nx] == 'D'){
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                    flag = 1;
                }
            }
        }
        if(flag){ flag = 0; depth++;}
        else break;
    }
    if(visited[ey][ex]) cout << visited[ey][ex] - 1;
    else cout << "KAKTUS";
    return 0;
}