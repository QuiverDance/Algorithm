#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int n, m, cnt;
vector<int> a, b;
map<int, int> mp1, mp2;

int main(void){
    cin >> n >> m;
    int tmp;
    for(int i = 0; i < n; i++){ cin >> tmp; a.push_back(tmp); mp1[tmp]++;}
    for(int i = 0; i < m; i++){ cin >> tmp; b.push_back(tmp); mp2[tmp]++;}
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    
    for(int i = 0; i < n; i++){
        int lo = 0, hi = m - 1;
        int mid;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(a[i] == b[mid]){
                cnt += mp2[b[mid]];
                if(mp1[a[i]] == 1) cnt++;
                else{
                    cnt += mp1[a[i]];
                    i += mp1[a[i]];
                }
                break;
            }
            if(a[i] > b[mid]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    cout << n + m - cnt;
    return 0;
}