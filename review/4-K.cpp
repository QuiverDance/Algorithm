#include<cstdio>
#include<vector>

using namespace std;

int t, n, e, visited[1004];
vector<int> adj[1004];

void dfs(int here){
    visited[here] = 1;
    for(int next : adj[here]){
        if(visited[next]) continue;
        dfs(next);
    }
}

int main(void){
    scanf("%d", &t);
    int a, b;
    while(t--){
        for(int i = 0; i <= n; i++) adj[i].clear();
        fill(&visited[0], &visited[0] + 1004, 0);

        scanf("%d %d", &n, &e);
        for(int i = 0; i < e; i++){
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            dfs(i);
            cnt++;
        }
        if(e == n - 1 && cnt == 1)  printf("tree\n");
        else printf("graph\n");
    }
    return 0;
}