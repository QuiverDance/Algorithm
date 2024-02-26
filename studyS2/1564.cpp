/*
    #1564 랜선 자르기
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k, ret = -1;
vector<int> v;
int main(){
    cin >> k >> n;
    int num;
    for(int i = 0 ; i < k ; i++){
        cin >> num;
        v.push_back(num);
    } 
    sort(v.begin(), v.end());
    long long lo = 1, hi = v[k - 1], mid, sum;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        sum = 0;
        for(int i = 0 ; i < k ; i++){
            if(v[i] / mid > 0) sum += v[i] / mid;
        }
        if(sum >= n){
            lo = mid + 1;
            ret = max(ret, mid);
        }
        else hi = mid - 1;
    }
    cout << ret;
    
    return 0;
}