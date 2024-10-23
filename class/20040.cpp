/*
    #20040 사이클게임
*/
#include<iostream>
using namespace std;

int n, m, parent[500004];
int getRoot(int node){
    if(node == parent[node]) return node;
    return parent[node] = getRoot(parent[node]);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) parent[i] = i;
    int st, ed;
    for(int i = 1; i <= m; i++){
        cin >> st >> ed;

        int r1 = getRoot(st);
        int r2 = getRoot(ed);
        if(r1 == r2){
            cout << i; return 0;
        }
        parent[r2] = r1;
    }
    cout << 0;
    return 0;
}