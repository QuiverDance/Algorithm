#include<iostream>
#include<vector>

using namespace std;

int n, ret;
bool prim[4000004];
vector<int> v;

int main(void){
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(prim[i]) continue;
        for(int j = i * 2; j <= n; j += i){
            prim[j] = 1;
        }
    }
    for(int i = 2; i <= n; i++){
        if(!prim[i]) v.push_back(i); 
    }
    int l = 0, sum = 0;
    int i = 0;
    while(true){
        if(sum >= n) sum -= v[l++];
        else if(i == v.size()) break;
        else sum += v[i++];
        if(sum == n) ret++;

    }
    cout << ret;
    return 0;
}