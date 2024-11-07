/*
    #1766 문제집
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, inorder[32004];
vector<int> adj[32004];
priority_queue<int, vector<int>, greater<int>> pq;
int main(void){
    cin >> n >> m;
    int from, to;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        inorder[to]++;
    }
    for(int i = 1; i <= n; i++){
        if(inorder[i] == 0) pq.push(i);
    }
    int cur;
    while(!pq.empty()){
        cur = pq.top(); pq.pop();
        cout << cur << " ";
        for(int next : adj[cur]){
            inorder[next]--;
            if(inorder[next] == 0) pq.push(next);
        }
    }
    return 0;
}