#include<iostream>
using namespace std;

int n, m, pnum[1004], cnt;
int main(void){
    pnum[1] = 1;
    for(int i = 2; i <= 1000; i++){
        if(pnum[i]) continue;
        for(int j = i * 2; j <= 1000; j += i) pnum[j] = 1;
    }
    cin >> n;
    while(n--){
        cin >> m;
        if(!pnum[m]) cnt++;
    }
    cout << cnt;
    return 0;
}