/*
    #1717 집합의 표현
*/
#include<iostream>
using namespace std;

int n, m, set[1000004];
int getRoot(int node){
    if(set[node] == node) return node;
    return set[node] = getRoot(set[node]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        set[i] = i;
    }
    int op, num1, num2;
    for(int i = 0; i < m; i++){
        cin >> op >> num1 >> num2;
        int root1 = getRoot(num1), root2 = getRoot(num2);
        if(op == 1){
            cout << (root1 == root2 ? "YES" : "NO") << '\n';
        }
        else{
            if(root1 < root2) set[root2] = root1;
            else set[root1] = root2;
        }
    }
    return 0;
}