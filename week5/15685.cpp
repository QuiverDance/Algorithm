#include<iostream>
#include<vector>

using namespace std;

int dy[] = {0, -1, 0 , 1};
int dx[] = {1, 0, -1, 0};
vector<int> dragon[4][11];

int cnt, n, x, y, d, g, board[101][101];

void makeDragon(){
    for(int i = 0; i < 4; i++){
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i + 1) % 4);
        for(int j = 2; j <= 10; j++){
            int t = dragon[i][j - 1].size();
            for(int k = t - 1; k >= 0; k--){
                dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
            }
            for(int k = 0; k < t; k++){
                dragon[i][j].push_back(dragon[i][j - 1][k]);
            }
        }
    }
}

void go(int x, int y, int d, int g){
    board[x][y] = 1;
    for(int i = 0; i <= g; i++){
        for(int dir : dragon[d][i]){
            x += dx[dir]; y += dy[dir];
            board[x][y] = 1;
        }
    }
}

int main(void){
    cin >> n;
    makeDragon();
    for(int i = 0; i < n; i++){
        cin >> x >> y >> d >> g;
        go(x, y, d, g);
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}