/*
    #14889 스타트와 링크
*/
#include<iostream>
#include<vector>
using namespace std;

int n, a[24][24], ret = 1e9;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    for(int t = 1; t < (1 << n); t++){
        vector<int> v1, v2;
        for(int i = 0; i < n; i++){
            if(t & (1 << i)) v1.push_back(i);
            else v2.push_back(i);
        }
        if(v1.size() != n / 2) continue;

        int sum = 0;
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < n / 2; j++){
                sum += a[v1[i]][v1[j]];
                sum -= a[v2[i]][v2[j]];
            }
        }
        ret = min(ret, abs(sum));
    }
    cout << ret;
    return 0;
}