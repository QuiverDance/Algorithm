#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, plug[104], order[104], ret;
vector<int> v;
int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> order[i];
    for(int i = 0; i < k; i++){
        if(plug[order[i]]) continue;
        if(v.size() == n){
            int last = 0, target;
            for(int cur : v){
                int first = 1e8;
                for(int j = i + 1; j < k; j++){
                    if(cur == order[j]){
                        first = j; break;
                    }
                }
                if(last < first){
                    last = first; target = cur;
                }
            }
            plug[target] = 0; v.erase(find(v.begin(), v.end(), target));
            ret++;
        }
        plug[order[i]] = 1; v.push_back(order[i]);
    }
    cout << ret;
    return 0;
}