#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Nutrition_{
    int p, f, s, v, cost;
} Nutrition;

int n, mp, mf, ms, mv, ret = 1e9;
Nutrition a[16];
map<int, vector<vector<int>>> min_mp;

int main(){
    cin >> n >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++){
        cin >> a[i].p;
        cin >> a[i].f;
        cin >> a[i].s;
        cin >> a[i].v;
        cin >> a[i].cost;
    }
    for(int i = 0; i < (1 << n); i++){
        int sum = 0;
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                sum += a[j].cost;
                v.push_back(j + 1);
            }
        }
        if(sum <= ret){
            ret = sum;
            min_mp[sum].push_back(v);
        }
    }
    cout << ret;
    vector<vector<int>> temp = min_mp[ret];
    sort(temp.begin(), temp.end());
    for(int it : temp[0]){
        cout << it << " ";
    }
    return 0;
}