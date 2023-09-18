#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int n, k, visited[100004];
map<int, int> mp;
int main(){
    cin >> n >> k;

    if(n == k){ cout << 0 << '\n' << n; return 0; }

    queue<int> q;
    visited[n] = 1;
    mp[n] = -1;
    q.push(n);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int nx : {x - 1, x + 1, x * 2}){
            if(nx < 0 || nx > 100000) continue;
            if(!visited[nx]){
                q.push(nx);
                visited[nx] = visited[x] + 1;
                mp[nx] = x;
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    vector<int> v;
    for(int cur = k; cur != n; cur = mp[cur]) v.push_back(cur);
    v.push_back(n);
    reverse(v.begin(), v.end());
    for(int i : v) cout << i << " ";

    return 0;
}