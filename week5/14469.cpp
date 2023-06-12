#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, a, d, ret;
vector<pair<int, int>> v;
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &d);
        v.push_back({a, d});
    }
    sort(v.begin(), v.end());
    ret = v[0].first + v[0].second;
    for(int i = 1; i < n; i++){
        if(ret > v[i].first){
            ret += v[i].second;
        }
        else
            ret = v[i].first + v[i].second;
    }
    printf("%d", ret);
    return 0;
}