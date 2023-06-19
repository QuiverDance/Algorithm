#include<iostream>

using namespace std;

typedef long long ll;
int n, m, a[100004], ret, sum, mx, lo, hi;

bool check(int mid){
    int cur = mid, cnt = 1;
    for(int i = 0; i < n; i++){
        if(cur - a[i] < 0){
            cnt++;
            cur = mid;
        }
        cur -= a[i];

    }
    return cnt <= m;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){ cin >> a[i]; sum += a[i]; mx = max(mx, a[i]); }
    
    lo = mx; hi = sum;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
            ret = mid;
        }
        else lo = mid + 1;
    }
    cout << ret;
    return 0;
}