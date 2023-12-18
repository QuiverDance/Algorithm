#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, k, ret, a[104][104], b[104][104], visited[104][104];
vector<tuple<int, int, int>> orders;
vector<int> order_idx;
int dir, sx, sy, ex, ey;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
vector<pair<int, int>> vv;

void go(int y, int x, int first){
    if(!first && y == sy && x == sx) dir++; 
	if(!first && y == sy && x == ex) dir++; 
	if(!first && y == ey && x == ex) dir++;
	if(!first && y == ey && x == sx) dir++; 
	int ny = y + dy[dir]; 
	int nx = x + dx[dir]; 
	if(visited[ny][nx]) return;
	visited[ny][nx] = 1; 
	vv.push_back({ny, nx});
	go(ny, nx, 0); 
}
void rotateBoard(tuple<int, int, int> order){
    int x, y, s;
    tie(x, y, s) = order;
    for(int i = 1; i <= s; i++){
		sy = y - 1 * i; 
		sx = x - 1 * i; 
		ey = y + 1 * i; 
		ex = x + 1 * i; 
		vv.clear();
		dir = 0;
		memset(visited, 0, sizeof(visited));  
		visited[sy][sx] = 1; 
		vv.push_back({sy, sx});
		go(sy, sx, 1); 
		vector<int> vvv; 
		for(pair<int, int> c : vv)vvv.push_back(b[c.first][c.second]); 
		rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
		for(int i = 0; i < vv.size(); i++) b[vv[i].first][vv[i].second] = vvv[i]; 
    }

}

int solve(){
    for(int idx : order_idx) rotateBoard(orders[idx]);
    int _ret = 1e9;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum =+ b[i][j];
        }
        _ret = min(_ret, sum);
    }
    return _ret;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int t1, t2, t3;
    for(int i = 0; i < k; k++){
        cin >> t1 >> t2 >> t3;
        orders.push_back({t1 - 1, t2 - 1, t3});
        order_idx.push_back(i);
    }
    do{
        memcpy(b, a, sizeof(a));
        ret = min(ret, solve());
    }while(next_permutation(order_idx.begin(), order_idx.end()));
    cout << ret;
    return 0;
}