/*
    #1080 행렬
*/
#include<iostream>
using namespace std;

int n, m, a[54][54], b[54][54], ret;
void flip(int sy, int sx){
    int y, x;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            y = sy + i; x = sx + j;
            a[y][x] = !a[y][x];
        }
    }
}
void print(){
    cout << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) scanf("%1d", &b[i][j]);
    }
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &num);
            if(num == b[i][j]) a[i][j] = 1;
        }
    }

    if(n < 3 || m < 3){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 0){
                    cout << -1; return 0;
                }
            }
        }
        cout << 0; return 0;
    }
    
    for(int i = 0; i <= n - 3; i++){
        for(int j = 0; j <= m - 3; j++){
            if(a[i][j] == 1) continue;
            ret++;
            flip(i, j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){
                ret = -1; break;
            }
        }
    }
    cout << ret;
    return 0;
}