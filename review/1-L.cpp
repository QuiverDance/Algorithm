#include<iostream>
#include<vector>
using namespace std;

int n, m, k, ret;
vector<int> v;

int main(){
    cin >> n >> m;
    if(m > 200000){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++){
        cin >> k; v.push_back(k);
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] + v[j] == m) ret++;
        }
    }
    cout << ret;
    return 0;
}