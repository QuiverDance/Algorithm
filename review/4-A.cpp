#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Nutrition_{
    int p = 0, f = 0, s = 0, v = 0, cost = 0;
    void add(Nutrition_ amount){
        p += amount.p;
        f += amount.f;
        s += amount.s;
        v += amount.v;
        cost += amount.cost;
    }
} Nutrition;

int n, mp, mf, ms, mv, ret = 1e9;
Nutrition a[16];
map<int, vector<vector<int>>> min_mp;

bool validation(Nutrition nutrition){
    if(nutrition.p < mp || nutrition.f < mf || nutrition.s < ms || nutrition.v < mv) return false;
    return true;
}

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
        Nutrition sum;
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                sum.add(a[j]);
                v.push_back(j + 1);
            }
        }
        if(sum.cost <= ret && validation(sum)){
            ret = sum.cost;
            min_mp[ret].push_back(v);
        }
    }
    if(ret == 1e9){
        cout << "-1";
        return 0;
    }
    cout << ret << '\n';
    vector<vector<int>> temp = min_mp[ret];
    sort(temp.begin(), temp.end());
    for(int it : temp[0]){
        cout << it << " ";
    }
    return 0;
}