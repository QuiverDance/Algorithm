#include<iostream>
#include<string>
using namespace std;

int n, t, sum;
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%1d", &t);
        sum += t;
    }
    printf("%d", sum);
    return 0;
}