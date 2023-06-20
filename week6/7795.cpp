#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int t, n, m, ret;
vector<int> a, b;

int main(void){
    cin >> t;
    int tmp;
    while(t--){
        ret = 0; a.clear(); b.clear();
        cin >> n >> m;
        for(int i = 0; i < n; i++){ cin >> tmp; a.push_back(tmp);}
        for(int i = 0; i < m; i++){ cin >> tmp; b.push_back(tmp);}
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        for(int i = 0; i < n; i++){
            if(a[i] > b[m - 1]){ ret += m; continue;}
            if(a[i] < b[0]) continue;
            int lo = 0, hi = m - 1;
            int mid = (lo + hi) / 2;
            while(lo <= hi){
                if(a[i] > b[mid]) lo = mid + 1;
                else hi = mid - 1;
                mid = (lo + hi) / 2;
            }
            if(a[i] > b[mid])
                ret += mid + 1;
            else
                ret += mid;
            
        }
        cout << ret << '\n';
    }
    return 0;
}