/*
    #11057  오르막 수
*/
#include<iostream>
#define DIV 10007
using namespace std;

int n, dp[1004][10], sum;
int solve(int h, int num){
    if(h == 1) return 1;

    int &ret = dp[h][num];
    if(ret > 0) return ret;

    if(num == 9)
        return ret = solve(h - 1, num) % DIV;
    else{
        for(int i = num; i < 10; i++)
            ret += solve(h - 1, i) % DIV;
    }
    return ret %= DIV;
}

int main(){
    cin >> n;
    for(int i = 0; i < 10; i++){
        sum += solve(n, i) % DIV;
    }
    cout << sum % DIV;
    return 0;
}