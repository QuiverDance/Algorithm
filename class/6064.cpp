/*
    #6064 카잉 달력
*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}
int t, m, n, x, y, ret = 0;
int main() {
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        ret = 0;
        for(int i = x; i <= lcm(m, n); i += m){
            int ny = i % n;
            if(ny == 0) ny = n;
            if(ny == y){
                ret = i; break;
            }
        }
        cout << (ret == 0 ? -1 : ret) << '\n';
    }
    return 0;
}