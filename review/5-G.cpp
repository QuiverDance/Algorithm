#include<iostream>
#include<vector>
using namespace std;

int n, ret, pnum[4000004];
vector<int> v;
int main(){
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 2; i <= n; i++){
        if(pnum[i]) continue;
        v.push_back(i);
        for(int j = i * 2; j <= n; j += i){
            pnum[j] = 1;
        }
    }
    int s = 0, e = 0, sum = v[0];
    while(e < v.size()){
        if(sum == n) ret++;
        if(sum >= n) sum -= v[s++];
        else sum += v[++e];
    }
    cout << ret;
    return 0;
}