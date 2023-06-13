#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int s, e, cnt[100004], n;
vector<int> v;
long long ret;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a; v.push_back(a);
    }
    while(e < n){
        if(!cnt[v[e]]){
            cnt[v[e]]++;
            e++;
        }
        else{
            ret += (long long)(e - s);
            cnt[v[s]]--;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2;
    cout << ret;
    return 0;
}