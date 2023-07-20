#include<iostream>
using namespace std;

int n, m, pnum[10004], sum, ret = 0;
int main(void){
    pnum[1] = 1;
    for(int i = 2; i <= 10000; i++){
        if(pnum[i]) continue;
        for(int j = i * 2; j <= 10000; j += i) pnum[j] = 1;
    }
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        if(pnum[i]) continue;
        if(!ret) ret = i;
        sum += i;
    }
    if(ret == 0) cout << -1;
    else cout << sum << '\n' << ret;
    return 0;
}