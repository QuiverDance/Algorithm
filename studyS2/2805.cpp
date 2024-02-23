/*
    #2805 나무 자르기
*/
#include <iostream>
#include <vector>
using namespace std;

long long n, m, ret = -1;
vector<int> v;
int main(){
    cin >> n >> m;
    int num;
    for(int i = 0 ; i < n ; i++) cin >> num, v.push_back(num);

    long long lo = 0, hi = 1e9, mid, sum;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(v[i] - mid > 0) sum += v[i] - mid;
        }
        if(sum >= m){
            lo = mid + 1;
            if(mid > ret) ret = mid;
        }
        else hi = mid - 1;
    }
    cout << ret;
    
    return 0;
}