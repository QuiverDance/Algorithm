#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
ll n, c, a[34], ret;
vector<int> v1, v2;

void go(int idx, int _n, vector<int> &v, int sum){
    if(sum > c) return;
    if(idx > _n){
        v.push_back(sum);
        return;
    }
    go(idx + 1, _n, v, sum);
    go(idx + 1, _n, v, sum + a[idx]);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    for(int i = 0 ; i < n; i++) cin >> a[i];

    go(0, n / 2 - 1, v1, 0);
    go(n / 2, n - 1, v2, 0);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i : v1){
        if(c - i >= 0) ret += (int)(upper_bound(v2.begin(), v2.end(), c - i) - v2.begin());
    }
    cout << ret;
    return 0;
}