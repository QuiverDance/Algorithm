/*
    #30804 과일 탕후루
*/
#include<iostream>
#include<map>
using namespace std;

int n, a[200004], cnt[10], c_num, ret;
int main() {
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0;
    for(int r = 0; r < n; r++){
        cnt[a[r]]++;
        if(cnt[a[r]] == 1) c_num++;

        while(l < r){
            if(c_num <= 2) break;
            cnt[a[l]]--;
            if(cnt[a[l]] == 0) c_num--;
            l++;
        }
        ret = max(ret, r - l + 1);
    }
    cout << ret;
    return 0;
}