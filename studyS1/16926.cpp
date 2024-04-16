/*
    #16926 배열 돌리기 1
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, t, a[304][304];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
void rotate_vector(int sy, int sx, int nn, int mm){
    vector<int> temp;
    temp.push_back(a[sy][sx]);
    int d = 0, y = sy, x = sx;
    while(true){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny == sy && nx == sx) break;
        if(ny < sy || nx < sx || ny >= sy + nn || nx >= sx + mm){
            d++; continue;
        }
        temp.push_back(a[ny][nx]); 
        y = ny; x = nx;
    }
    rotate(temp.rbegin(), temp.rbegin() + 1, temp.rend());
    
    d = 0, y = sy, x = sx; 
    a[y][x] = temp[0];
    int t = 1;
    while(true){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny == sy && nx == sx) break;
        if(ny < sy || nx < sx || ny >= sy + nn || nx >= sx + mm){
            d++; continue;
        }
        y = ny; x = nx;
        a[ny][nx] = temp[t++];
    }
}

void rotate(){
    int t = min(n, m) / 2;
    for(int i = 0; i < t; i++){
        rotate_vector(i, i, n - 2 * i, m - 2 * i);
    }
}
int main(){
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }

    while(t--){
        rotate();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}