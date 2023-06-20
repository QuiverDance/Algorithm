#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
struct Room{
    ll t, a, h;
    Room(ll t, ll a, ll h) : t(t), a(a), h(h){}
};

ll n, m, ret;
vector<Room> v;

bool check(ll mid){
    ll hp = mid, atk = m;
    for(int i = 0; i < n; i++){
        if(v[i].t == 1){
            ll cnt = v[i].h / atk + (v[i].h % atk ? 1 : 0);
            hp -= v[i].a * (cnt - 1);
        }
        else{
            atk += v[i].a;
            hp = min(hp + v[i].h, mid);
        }
        if(hp <= 0) return false;
    }
    return true;
}

int main(void){
    cin >> n >> m;
    ll t, a, h;
    for(int i = 0; i < n; i++){
        cin >> t >> a >> h;
        v.push_back(Room(t, a, h));
    }
    ll lo = 1, hi = 1e18 + 4;
    ll mid;
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