/*
    #1991 트리 순회
*/
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> adj[30];
void preorder(int node){
    if(node == -1) return;
    cout << (char)(node + 'A');
    preorder(adj[node][0]);
    preorder(adj[node][1]);
}
void inorder(int node){
    if(node == -1) return;
    inorder(adj[node][0]);
    cout << (char)(node + 'A');
    inorder(adj[node][1]);
}
void postorder(int node){
    if(node == -1) return;
    postorder(adj[node][0]);
    postorder(adj[node][1]);
    cout << (char)(node + 'A');
}
int main(){
    cin >> n;
    char c, node;
    for(int i = 0; i < n; i++){
        cin >> node;
        for(int j = 0; j < 2; j++){
            cin >> c;
            if(c == '.') adj[node -'A'].push_back(-1);
            else adj[node -'A'].push_back(c - 'A');
        }
    }
    preorder(0); cout << '\n';
    inorder(0); cout << '\n';
    postorder(0);
    return 0;
}