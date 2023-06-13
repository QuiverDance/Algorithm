#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, a, x, ret;
vector<int> v;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    cin >> x;

    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1;
    while(l < r){
        if(v[l] + v[r] == x){
            ret++; l++; r--;
        }
        else if(v[l] + v[r] < x) l++;
        else r--;
    }
    cout << ret;
    return 0;
}