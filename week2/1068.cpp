#include<iostream>

using namespace std;

int n, d_node, r_node, cnt = 0;
int tree[50], visited[50];

void dfs(int node){
    visited[node] = 1;
    
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(tree[i] == node && !visited[i]){
            dfs(i);
            flag = 1;
        }
    }
    if(flag == 0) cnt++;
}
int main(void){
    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        tree[i] = a;
        if(a == -1) r_node = i;
    }
    cin >> d_node;

    if(r_node == d_node){
        cout << 0;
        return 0;
    }
    tree[d_node] = -2;
    dfs(r_node);
    cout << cnt;
    return 0;
}