#include<iostream>
using namespace std;

int n;
int main(void){
    cin >> n;
    for(int i = 1; i <= 9; i++)
        printf("%d * %d = %d\n", n, i, n * i);
    return 0;
}