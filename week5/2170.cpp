#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, ret;
vector<pair<int, int>> v;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int l = -1e9;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second <= l) continue;
        if(v[i].first >= l) ret += v[i].second - v[i].first;
        else ret += v[i].second - l;
        l = v[i].second;
    }
    cout << ret;
    return 0;
}