#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, m;

bool check(int num, vector<int> &v){
    int lo = 0, hi = v.size() - 1;
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(v[mid] > num) hi = mid - 1;
        else if(v[mid] == num) return true;
        else lo = mid + 1;
    }
    return false;
}

int main(void){
    scanf("%d", &t);
    int tmp;
    while(t--){
        vector<int> v;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp); v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &tmp);
            if(check(tmp, v)) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}