/*
    #1043 거짓말
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, k, parent[54], ret, truth;
vector<int> a[54];
int getRoot(int node){
    if(parent[node] == node) return node;
    return parent[node] = getRoot(parent[node]);
}

void merge(int node1, int node2){
    int r1 = getRoot(node1);
    int r2 = getRoot(node2);
    if(r1 == r2) return;
    if(r1 < r2)
        parent[r2] = parent[r1];
    else
        parent[r1] = parent[r2];
}

int main() {
    cin >> n >> m >> k;
    if(k == 0){ cout << m; return 0;}
    
    for(int i = 0; i <= n; i++)
        parent[i] = i;
    
    int num;
    for(int i = 0 ; i < k; i++){
        cin >> num; parent[num] = 0;
    }
 
    int num2;
    for(int i = 0; i < m; i++){
        cin >> k;
        cin >> num;
        a[i].push_back(num); 
        for(int j = 1; j < k; j++){
            cin >> num2;
            a[i].push_back(num2);
            merge(num, num2);
        }
    }
    
    ret = m;
    for(int i = 0; i < m; i++){
        for(int p : a[i]){
            if(getRoot(p) == 0){
                ret--;
                break;
            }
        }
    }
    cout << ret;
}