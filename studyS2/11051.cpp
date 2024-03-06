/*
    이항 계수 2
*/
#include<iostream>
using namespace std;

int n, k;
int dp[1004][1004];
int combi(int a, int b){
    if(a == b || b == 0) return 1;
    int &ret = dp[a][b];
    if(ret > 0) return ret;
    ret = (combi(a - 1, b - 1) + combi(a - 1, b)) % 10007;
    return ret;
}

int main(){
    cin >> n >> k;
    cout << combi(n, k);
    return 0;
}