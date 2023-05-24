#include<iostream>
#include<string>

using namespace std;

int h, w;
string s;
int board[101][101], visited[101][101];

void dfs(int y, int x){
    int nx = x + 1;
    if(board[y][nx] != 'c' && visited[y][nx] == -1){
        visited[y][nx] = visited[y][x] + 1;
        dfs(y, nx);
    }
}

int main(void){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < w; j++){
            board[i][j] = s[j];
            visited[i][j] = -1;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(board[i][j] == 'c' && visited[i][j] == -1){
                visited[i][j] = 0;
                dfs(i, j);
            }
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
            cout << visited[i][j] << " ";
        cout << '\n';
    }
    return 0;
}