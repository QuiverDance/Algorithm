#include<iostream>
using namespace std;

int a, b;
int main(void){
    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", a + b);
    }   
    return 0;
}