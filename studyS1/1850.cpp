/*
    #1850 최대공약수
*/
#include <iostream>
using namespace std;

typedef long long ll;
ll a, b, k;
ll gcd(ll aa, ll bb){
    if(bb == 0) return aa;
    return gcd(bb, aa % bb);
}
int main() {
    cin >> a >> b;

    k = gcd(a, b);
    while(k--){
        cout << "1";
    }
    return 0;
}
