/*
    #4948 베르트랑 공준
*/
#include<iostream>
using namespace std;

int n, a[300000], ret;
int main(){
    while(scanf("%d", &n)){
        if(n == 0) break;
        a[1] = 1; ret = 0;
        for(int i = 2; i <= 2*n; i++){
            if(a[i]) continue;
            for(int j = i * 2; j <= 2*n; j += i){
                a[j] = 1;
            }
        }
        for(int i = n + 1; i <= 2*n; i++){
            if(!a[i]) ret++;
        }
        cout << ret << '\n';
    }
    return 0;
}