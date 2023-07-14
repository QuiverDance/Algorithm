#include<iostream>
#include<cstring>
using namespace std;

int n, mx = 0, sum, t;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        mx = max(mx, t);
        sum += t;
    }
    printf("%lf", (double)(sum * 100) / (mx * n));
    return 0;
}