#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, l, ret;
vector<pair<int, int>> v;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int e = 0;
    for(int i = 0; i < n; i++){
        if(v[i].first > e){
            e = v[i].first;
        }
        while(e < v[i].second){
            e += l; ret++;
        }
    }
    cout << ret;
    return 0;
}