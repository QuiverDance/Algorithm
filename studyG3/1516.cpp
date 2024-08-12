/*
    #1516 게임 개발
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, a[504], front[504], dp[504];
vector<int> adj[504];
queue<int> q;
int main(){
    cin >> n;
    int num;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        while(true){
            cin >> num;
            if(num == -1) break;
            front[i]++;
            adj[num].push_back(i);
        }
    }
    for(int i = 1; i<= n; i++){
        if(front[i] == 0){
            q.push(i); dp[i] = a[i];
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int next : adj[cur]){
            front[next]--;
            dp[next] = max(dp[next], dp[cur] + a[next]);
            if(front[next] == 0){
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dp[i] << '\n';
    return 0;
}