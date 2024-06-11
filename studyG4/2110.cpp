/*
    #2110 공유기 설치
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, c, ret;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int l = 1, r = v[n - 1] - v[0];
    int mid, cnt, prev;
    while(l <= r){
        mid = (l + r) / 2;
        cnt = 1;
        prev = 0;
        for(int i = 1; i < n; i++){
            if(v[i] - v[prev] >= mid){
                cnt++; prev = i;
            }
        }
        if(cnt >= c){
            ret = max(ret, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ret;
    return 0;
}