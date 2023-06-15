#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int n, k, l, ret;
int board[104][104];
queue<pair<int, int>> body;
queue<pair<int, char>> mv;
int dy[] = {0 , 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int turn(int cur, char d){
    switch (cur)
    {
    case 0:
        if(d == 'L') return 3;
        else return 1;
        break;
    case 1:
        if(d == 'L') return 0;
        else return 2;
        break;
    case 2:
        if(d == 'L') return 1;
        else return 3;
        break;
    case 3:
        if(d == 'L') return 2;
        else return 0;
        break;                
    default:
        break;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int a, b;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        board[a][b] = 2;
    }
    cin >> l;
    char c;
    for(int i = 0; i < l; i++){
        cin >> a >> c;
        mv.push({a, c});
    }
    int x = 1, y = 1, d = 0;
    board[y][x] = 1; body.push({1, 1});
    while(true){
        if(mv.size() && mv.front().first == ret){
            d = turn(d, mv.front().second); mv.pop();
        }
        int ny = y + dy[d], nx = x + dx[d];
        if(ny < 1 || nx < 1 || ny > n || nx > n) break;
        if(board[ny][nx] == 1) break;
        if(board[ny][nx] == 0){
            pair<int, int> tail = body.front();
            board[tail.first][tail.second] = 0;
            body.pop();
        }
        board[ny][nx] = 1; y = ny; x = nx;
        body.push({ny, nx});
        ret++;
    }
    cout << ret + 1;
    return 0;
}