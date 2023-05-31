#include<iostream>
#include<queue>

using namespace std;

int n, k;
int visited[100001], cnt[100001];
queue<int> q;

int d[] = {-1, 1};

int main(void){
    cin >> n >> k;
    if(n == k){
        cout << "0\n1";
        return 0;
    }
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    int x, nx;
    while(q.size()){
        x = q.front();
        q.pop();
        for(int i = 0; i < 3; i++){
            if(i == 2) nx = 2 * x;
            else nx = x + d[i];

            if(nx < 0 || nx > 100000) continue;
            if(visited[nx]){
                if(visited[nx] == visited[x] + 1) cnt[nx] += cnt[x];
                continue;
            }
            visited[nx] = visited[x] + 1;
            cnt[nx] += cnt[x];
            q.push(nx);
        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k];
    return 0;
}