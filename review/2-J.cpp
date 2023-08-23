#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int h, w, a[104][104], visited[104][104], num;
string s;
void dfs(int y, int x){
    int nx = x + 1;
    if(nx >= w || a[y][nx] == 'c') return;
    visited[y][nx] = visited[y][x] + 1;
    dfs(y, nx);
}

int main(){
    memset(visited, -1, sizeof(visited));
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < w; j++) a[i][j] = s[j];
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '.' || visited[i][j] != -1) continue;
            visited[i][j] = 0;
            dfs(i, j);
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cout << visited[i][j] << " ";
        cout << '\n';
    }
    return 0;
}