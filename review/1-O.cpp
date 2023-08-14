#include<iostream>
using namespace std;

int n;
int main(void){
    while(scanf("%d", &n) != EOF){
        long long num = 1, len = 1;
        while(true){
            if(num % n == 0){
                printf("%lld\n", len);
                break;
            }
            else{
                num = num * 10 + 1;
                num %= n;
                len++;
            }
        }
    }
    return 0;
}