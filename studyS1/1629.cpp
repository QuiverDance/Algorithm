/*
    #1629 곱셈
*/
#include<iostream>
#define ll long long
using namespace std;

int a, b, c;
ll solve(int e){
    if(e == 1) return a % c;
    
    ll ret = solve(e / 2);
    if(e % 2){
        return (a * ((ret * ret) %c)) %c;    
    }
    return (ret * ret) % c;

}

int main(){
    cin >> a >> b >> c;
    cout << solve(b);
    return 0;
}