/*
    #9184 신나는 함수 실행
*/
#include<iostream>
using namespace std;

int aa, bb, cc, dp[54][54][54];
int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    int &ret = dp[a][b][c];
    if(ret > 0) return ret;
    if(a > 20 || b > 20 || c > 20){
        return ret = w(20, 20, 20);
    }
    if(a < b && b < c){
        return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(){
    while(scanf("%d %d %d", &aa, &bb, &cc)){
        if(aa == -1 && bb == -1 && cc == -1) break;
        printf("w(%d, %d, %d) = %d\n", aa, bb, cc, w(aa, bb, cc));
    }
        
    return 0;
}