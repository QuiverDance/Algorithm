#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int n, k, visited[100004];
map<int, int> mp;
int main(){
    cin >> n >> k;

    if(n == k){ cout << 0 << '\n' << 1; return 0; }
    if(k < n){ cout << n - k << '\n' << 1; return 0; }

    queue<int> q;
    visited[n] = 1;
    mp[n] = 1;
    q.push(n);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int nx : {x + 1, x * 2}){
            if(nx > 100000) continue;
            if(!visited[nx]){
                q.push(nx);
                visited[nx] = visited[x] + 1;
                mp[nx] += mp[x];
            }
            else if(visited[nx] == visited[x] + 1) 
                mp[nx] += mp[x];
        }
    }
    cout << visited[k] - 1 << '\n' << mp[k] - 1;
    return 0;
}