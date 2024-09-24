/*
    #10830 행렬 제곱
*/
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> vvi;
ll n, b;
vvi a, ret;

vvi mul(vvi m1, vvi m2){
    vvi t;
    for(int i = 0; i < n; i++){
        vector<int> tt;
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int k = 0; k < n; k++){
                sum += m1[i][k] * m2[k][j];
            }
            tt.push_back(sum % 1000);
        }
        t.push_back(tt);
    }
    return t;
}
vvi solve(ll e){
    if(e == 1) return a;
    if(e == 2){
        return mul(a, a);
    }
    if(e % 2 == 1){
        vvi t = solve((e - 1) / 2);
        return mul(a, mul(t, t));
    }
    else{
        vvi t = solve(e / 2);
        return mul(t, t);
    }
}
int main(){
    cin >> n >> b;
    int num;
    for(int i = 0; i < n; i++){
        vector<int> vnum;
        for(int j = 0; j < n; j++){
            cin >> num;
            vnum.push_back(num);
        }
        a.push_back(vnum);
    }
    ret = solve(b);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << ret[i][j] % 1000 << " ";
        cout << '\n';
    }
    return 0;
}