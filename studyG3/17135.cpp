/*
    #17135 캐슬 디펜스
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, d, a[19][19], k_cnt, ret;
int archers[3];
bool isEnd(int e[19][19]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(e[i][j] == 1) return false;
        }
    }
    return true;
}
vector<pair<int, int>> kill(int e[19][19]){
    vector<pair<int, int>> target;
    for(int k = 0; k < 3; k++){
        int y = n, x = archers[k];
        vector<pair<int, pair<int, int>>> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(e[i][j] == 0) continue;
                int dist = abs(y - i) + abs(x - j);
                if(dist > d) continue;
                v.push_back({dist, {j, i}});
            }
        }
        if(!v.empty()){
            sort(v.begin(), v.end());
            target.push_back({v[0].second.second, v[0].second.first});
        }
    }
    return target;
}
void solve(){
    int e[19][19];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) e[i][j] = a[i][j];
    }
    while(!isEnd(e)){
        vector<pair<int, int>> targets = kill(e);
        for(auto t : targets){
            if(e[t.first][t.second] == 1){
                cnt++;
                e[t.first][t.second] = 0;
            }
        }
        for(int i = n - 1; i > 0; i--){
            for(int j = 0; j < m; j++){
                e[i][j] = e[i - 1][j];
            }
        }
        for(int j = 0; j < m; j++) e[0][j] = 0;
    }
    ret = max(ret, cnt);
}
int main() {
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int k = 0; k < m; k++){
        for(int i = k + 1; i < m; i++){
            for(int j = i + 1; j < m; j++){
                archers[0] = k;
                archers[1] = i;
                archers[2] = j;
                solve();
            }
        }
    }
    cout << ret;
    return 0;
}