/*
    #1389 케빈 베이컨의 6단계 법칙
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;

int n, m, a[104][104];
vector<pair<long long, int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(&a[0][0], &a[0][0] + 104 * 104, INF);
    for(int i = 0; i < n; i++) a[i][i] = 0;
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        from--; to--;
        a[from][to] = 1;
        a[to][from] = 1;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = 0; j < n; j++){
            sum += a[i][j];
        }
        v.push_back({sum, i});
    }
    sort(v.begin(), v.end());
    cout << v[0].second + 1;
    return 0;
}