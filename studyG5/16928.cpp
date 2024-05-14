/*
    #16928 뱀과 사다리 게임
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m, a[104], visited[104];
queue<int> q;
int main() {
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < n + m; i++){
        cin >> from >> to;
        a[from] = to;
    }
    q.push(1); visited[1] = 1;
    int pos;
    while(!q.empty()){
        pos = q.front(); q.pop();
        for(int i = 1; i <= 6; i++){
            if(pos + i > 100) continue;
            if(a[pos + i] > 0 && (visited[a[pos + i]] > visited[pos] + 1 || visited[a[pos + i]] == 0)){
                visited[a[pos + i]] = visited[pos] + 1;
                q.push(a[pos + i]);
            }
            else if(a[pos + i] == 0 && (visited[pos + i] > visited[pos] + 1 || visited[pos + i] == 0)){
                visited[pos + i] = visited[pos] + 1;
                q.push(pos + i);
            }
        }
    }
    cout << visited[100] - 1;
    return 0;
}