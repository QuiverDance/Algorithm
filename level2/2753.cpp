#include<iostream>
using namespace std;

int y;
int main(void){
    cin >> y;
    if(y % 4) cout << 0;
    else{
        if(!(y % 400)) cout << 1;
        else if (!(y % 100)) cout << 0;
        else cout << 1;
    }
    return 0;
}