#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    int cur = v[0].first;
    ret = 1;
    for(int i = 1; i < n; i++){
        if(v[i].second >= cur){
            ret++;
            cur = v[i].first;
        }
    }
    printf("%d", ret);
    return 0;
}