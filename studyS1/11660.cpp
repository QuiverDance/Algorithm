/*
    #11660 구간 합 구하기 5
*/
#include <iostream>
using namespace std;

int n, m, sum[1100][1100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int num;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> num;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num;
        }
    }
    
    int fx, fy, sx, sy;
    for(int i = 0; i < m; i++){
        cin >> fx >> fy >> sx >> sy;
        cout << sum[sx][sy] - sum[fx - 1][sy] - sum[sx][fy - 1] + sum[fx - 1][fy - 1] << '\n';
    }

    return 0;
}