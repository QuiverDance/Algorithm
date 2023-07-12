#include<iostream>
using namespace std;

int x, y;
int main(void){
    cin >> x >> y;
    if(x > 0){
        printf("%d", y > 0 ? 1 : 4);
    }
    else{
        printf("%d", y > 0 ? 2 : 3);
    }
    return 0;
}