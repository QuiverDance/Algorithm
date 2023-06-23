#include<iostream>
#include<vector>

using namespace std;

int n, num[1004], pre[1004], cnt[1004];
int ret, idx;
vector<int> v;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    fill(&pre[0], &pre[0] + 1004, -1);
    fill(&cnt[0], &cnt[0] + 1004, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(num[j] < num[i] && cnt[i] < cnt[j] + 1){
                cnt[i] = cnt[j] + 1;
                pre[i] = j;
                if(ret < cnt[i]){
                    ret = cnt[i]; idx = i;
                }
            } 
        }
    }
    int i = idx;
    for(; pre[i] != -1; i = pre[i]){
        v.push_back(num[i]);
    }
    v.push_back(num[i]);
    cout << v.size() << '\n';
    for(i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
    return 0;
}