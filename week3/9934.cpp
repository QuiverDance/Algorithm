#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int k;
string s;
int v[1030];
vector<int> level[14];

void solve(int l, int r, int cnt){
    if(l > r) return;
    if(l == r) {
        level[cnt].push_back(v[r]);
        return;
    }
    int mid = (l + r) / 2;
    level[cnt].push_back(v[mid]);
    solve(l, mid - 1, cnt + 1);
    solve(mid + 1, r, cnt + 1);
}

int main(void){
    cin >> k;
    int _end = (int)pow(2, k) - 1; 
    for(int i = 0; i < _end; i++){
        cin >> v[i]; 
    }
    solve(0, _end, 1); 
    for(int i = 1; i <= k; i++){
        for(int j : level[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}