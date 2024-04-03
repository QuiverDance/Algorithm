/*
    #5014 스타트링크
*/
#include<iostream>
#include<queue>
using namespace std;

int f, s, g, u, d, visited[1000004];
queue<int> q;
int main(){
    cin >> f >> s >> g >> u >> d;
    visited[s] = 1;
    q.push(s);

    int y;
    while(!q.empty()){
        y = q.front(); q.pop();
        for(int dy : {u, -d}){
            int ny = y + dy;
            if(ny > f || ny < 1) continue;
            if(visited[ny]) continue;
            visited[ny] = visited[y] + 1;
            q.push(ny);
        }
    }
    if(visited[g])
        cout << visited[g] - 1;
    else
        cout << "use the stairs";
    return 0;
}