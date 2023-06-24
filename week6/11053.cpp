#include<iostream>

using namespace std;

int n, num[1004], cnt[1004], ret = 1;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];

    fill(cnt, cnt + 1004, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(num[j] < num[i] && cnt[i] < cnt[j] + 1){
                cnt[i] = cnt[j] + 1;
                ret = max(cnt[i], ret);
            }
        }
    }
    cout << ret;
    return 0;
}