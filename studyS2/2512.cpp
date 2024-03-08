/*
    #2512 예산
*/
#include<iostream>
using namespace std;

int n, m, a[100004], ret, mx;
long long sum;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        mx = max(mx, a[i]); sum += a[i];
    }
    cin >> m;
    
    if(sum <= m){
        cout << mx;
        return 0;
    }
    int lo = 0, hi = mx, mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += min(a[i], mid);
        }
        if(sum > m){
            hi = mid - 1; 
        }
        else {
            lo = mid + 1;
            ret = max(ret, mid);
        }

    }
    cout << ret;
    return 0;
}