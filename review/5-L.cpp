#include<iostream>
#include<vector>
using namespace std;

int n, s, a[24][24], ret = 1e8;
vector<int> t1, t2;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    for(int t = 0; t < (1 << n); t++){
        t1.clear(); t2.clear();
        for(int i = 0; i < n; i++){
            if(t & (1 << i)) t1.push_back(i);
            else t2.push_back(i);
        }
        if(t1.size() != t2.size()) continue;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < n / 2; j++){
                sum1 += a[t1[i]][t1[j]];
                sum2 += a[t2[i]][t2[j]];
            }
        }
        ret = min(ret, abs(sum1 - sum2));
    }
    cout << ret;
    return 0;
}