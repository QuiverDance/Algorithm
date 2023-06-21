#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
ll s, c, l, ret, sum;
vector<ll> v;

bool check(ll mid){
    int cnt = 0;
    for(int i = 0; i < s; i++){
        cnt += v[i] / mid;
    }
    return cnt >= c;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> s >> c;  
    for(int i = 0; i < s; i++){
        cin >> l;
        v.push_back(l); sum += l;
    }
    ll lo = 1, hi = 1e9;
    ll mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            lo = mid + 1;
            ret = mid;
        }
        else hi = mid - 1;
    }
    cout << sum - ret * c;
    return 0;
}