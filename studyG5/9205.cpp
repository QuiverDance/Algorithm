/*
    #9205 맥주 마시면서 걸어가기
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int t, n, sx, sy, ex, ey, visited[104], flag;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    int y, x;
    while(t--){
        memset(visited, 0, sizeof(visited));
        pair<int, int> store[104];
        queue<pair<int, int>> q;
        flag = 0;
        cin >> n >> sx >> sy;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            store[i] = {y, x};
        }
        cin >> ex >> ey;

        q.push({sy, sx});
        while(!q.empty()){
            tie(y, x) = q.front(); q.pop();
            if(abs(y - ey) + abs(x - ex) <= 1000){
                flag = 1; break;
            }
            for(int i = 0; i < n; i++){
                if(visited[i]) continue;
                int ny, nx; tie(ny, nx) = store[i];
                if(abs(y - ny) + abs(x - nx) > 1000) continue;
                
                visited[i] = 1; q.push({ny, nx});
            }
        }
        cout << (flag == 0 ? "sad" : "happy") << '\n';
    }
    return 0;
}