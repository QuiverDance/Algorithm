#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k, ret, plugged[104], order[104];
vector<int> tap;
int main(void){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> order[i];
    }
    for(int i = 0; i < k; i++){
        if(plugged[order[i]]) continue;
        if(tap.size() == n){
            int last = 0, dpos;
            for(int it : tap){
                int here = 1e8;
                for(int j = i + 1; j < k; j++){
                    if(it == order[j]){
                        here = j; break;
                    }
                }
                if(last < here){
                    last = here;
                    dpos = it;
                }
            }
            plugged[dpos] = 0;
            ret++;
            tap.erase(find(tap.begin(), tap.end(), dpos));
        }
        tap.push_back(order[i]); plugged[order[i]] = 1;
    }
    cout << ret;
    return 0;
}