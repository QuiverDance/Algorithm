#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, k, ret, a[104][104], b[104][104];
vector<tuple<int, int, int>> orders;
vector<int> order_idx;

int solve(){
    for(int idx : order_idx) rotateBoard(orders[idx]);
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int t1, t2, t3;
    for(int i = 0; i < k; k++){
        cin >> t1 >> t2 >> t3;
        orders.push_back({t1, t2, t3});
        order_idx.push_back(i);
    }
    do{
        memcpy(b, a, sizeof(a));
        ret = solve();
    }while(next_permutation(order_idx.begin(), order_idx.end()));

    return 0;
}