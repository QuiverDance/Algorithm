/*
    #6588 골드바흐의 추측
*/
#include<iostream>
using namespace std;

int n, a[1000004], flag;
int main(){
    for(int i = 2; i <= 1000000; i++){
        if(a[i]) continue;
        for(int j = i + i; j <= 1000000; j += i)
            a[j] = 1;
    }
    
    while(scanf("%d", &n)){
        if(n == 0) break;
        flag = 0;
        for(int i = 2; i <= n / 2; i++){
            if(a[i] || a[n - i]) continue;
            flag = 1;
            printf("%d = %d + %d\n", n, i, n - i);
            break;
        }
        if(flag == 0) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}