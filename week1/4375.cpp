#include<stdio.h>

int n;
int main(void){

    while (scanf("%d", &n) != EOF){
        long long cnt = 1, ret = 1;

        while(true){
            if(cnt % n == 0){
                printf("%lld\n", ret);
                break;
            }
            else{
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    
    return 0;
}