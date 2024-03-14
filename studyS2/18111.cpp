/*
    #18111 마인크래프트
*/
#include<iostream>
using namespace std;

int n, m, b, a[504][504], t = 1e9, h;
int mn = 300, mx;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){ cin >> a[i][j]; mn = min(mn, a[i][j]); mx = max(mx, a[i][j]); }
    }
    int cnt1, cnt2;
    for(int cur = mn; cur <= mx; cur++){
        cnt1 = 0; cnt2 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > cur) cnt1 += a[i][j] - cur;
                else cnt2 += cur - a[i][j];
            }
        }
        if(b + cnt1 - cnt2 < 0) break;
        if(cnt1 * 2 + cnt2 < t){
            t = cnt1 * 2 + cnt2; h = cur;
        }
        else if(cnt1 * 2 + cnt2 == t){
            h = max(h, cur);
        }
    }        
    cout << t << " " << h;
    return 0;
}