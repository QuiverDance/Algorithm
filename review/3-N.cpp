#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int k, a[1024], len;
vector<int> ret[10];

void solve(int l, int r, int depth){
    if(l > r || depth >= k) return;
    int mid = (l + r) / 2;
    ret[depth].push_back(a[mid]);
    solve(l, mid - 1, depth + 1);
    solve(mid + 1, r, depth + 1);
}

int main(){
    cin >> k;
    len = (int)pow(2, k) - 1;
    for(int i = 0; i < len; i++) cin >> a[i];
    solve(0, len, 0);
    for(vector<int> v : ret){
        if(v.empty()) continue;
        for(int it : v) cout << it << " ";
        cout << '\n';
    }
    return 0;
}