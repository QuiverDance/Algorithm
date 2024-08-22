/*
    #2473 세 용액
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n, ret[3], mn = 3e9;
vector<ll> v;
int main(){
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int l = i + 1, r = n - 1;
        while(l < r){
            ll sum = v[i] + v[l] + v[r];
            if(mn > abs(sum)){
                mn = abs(sum);
                ret[0] = v[i];
                ret[1] = v[l];
                ret[2] = v[r];
            }
            if(sum > 0) r--;
            else l++;
        }
    }
    for(int i = 0; i < 3; i++) cout << ret[i] << " ";
}