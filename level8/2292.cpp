#include<iostream>
using namespace std;

int n, pre = 1;
int main(void){
    cin >> n;
    int i = 1;
    while(n > 1){
        if(n > pre && n <= 3 * i * (i + 1) + 1) break;
        pre = 3 * i * (i + 1); i++;
    }
    if(n == 1) cout << 1;
    else cout << i + 1;
    return 0;
}