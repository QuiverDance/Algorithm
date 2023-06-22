#include<iostream>

using namespace std;

typedef long long ll;

ll x, y, z, ret = -1;
bool check(ll mid){
    if(z == (ll)(100 * (y + mid) / (x + mid)))
        return true;
    else return false;
}
int main(void){
    cin >> x >> y;
    if(x == y){
        cout << "-1";
        return 0;
    }
    z = (ll)(100 * y / x);
    ll lo = 1, hi = 1e9, mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
            ret = mid;
        }
        else lo = mid + 1;
    }
    cout << ret;
    return 0;
}