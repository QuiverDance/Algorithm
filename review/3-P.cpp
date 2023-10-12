#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n, a[104][104], ret = 1e9;
set<pair<int, int>> flowers;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int solve(vector<int> seeds){
    int cost = 0;
    for(int i = 0; i < 3; i++){
        int y = seeds[i] / n;
        int x = seeds[i] % n;
        flowers.insert({y, x});
        cost += a[y][x];
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            cost += a[ny][nx];
            flowers.insert({ny, nx});
        }
    }
    if(flowers.size() == 15) return cost;
    return 1e9; 
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    for(int i = 0; i < n * n; i++){
        for(int j = i + 1; j < n * n; j++){
            for(int k = j + 1; k < n * n; k++){
                flowers.clear();
                ret = min(ret , solve({i, j, k}));
            }
        }
    }
    cout << ret;
    return 0;
}