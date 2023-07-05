#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n, a[104], b[104], dp[104][10][10][10][2];
int _mod(int x){
    return (x < 0) ? x + 10 : x % 10;
}

int f(int idx, int x, int y, int z, int flag){
    if(idx == n) return 0;
    int &ret = dp[idx][x][y][z][flag];
    if(ret != -1) return ret;
    if(_mod(x + a[idx]) == _mod(b[idx])) return ret = min(f(idx + 1, y, z, 0, 0), f(idx + 1, y, z, 0, 1));
    ret = 1e9;
    int _flag = flag ? 1 : -1;
    for(int i = 0; i <= 3; i++){
        ret = min(ret, 1 + f(idx, _mod(x + i * _flag), y, z, flag));
        ret = min(ret, 1 + f(idx, _mod(x + i * _flag), _mod(y + i * _flag), z, flag));
        ret = min(ret, 1 + f(idx, _mod(x + i * _flag), _mod(y + i * _flag), _mod(z + i * _flag), flag));
    }
    return ret;
}

int main(void){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%1d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%1d", &b[i]);
    printf("%d", min(f(0, 0, 0, 0, 0), f(0, 0, 0, 0, 1)));    
    return 0;
}