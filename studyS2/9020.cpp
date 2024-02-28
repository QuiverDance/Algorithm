/*
    #골드바흐의 추측
*/
#include<iostream>
#include<vector>
using namespace std;

int t, n, a[10004], ret;
vector<int> v;
int main(){
    a[1] = 1;
    for(int i = 2; i <= 10000; i++){
        if(a[i]) continue;
        for(int j = i * 2; j <= 10000; j += i){
            a[j] = 1;
        }
    }
    for(int i = 2; i <= 10000; i++) if(!a[i]) v.push_back(i);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int lo = 0, hi = v.size() - 1, mid;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            //printf("lo : %d hi : %d mid : %d\n", lo, hi, mid);
            if(v[mid] >= n) hi = mid - 1;
            else lo = mid + 1; 
        }
        //printf("mid : %d, %d\n", mid, v[mid]);
        for(int i = 0; i < mid; i++){
            for(int j = i; j < mid; j++){
                //printf("%d + %d = %d\n", v[i], v[j], v[i] + v[j]);
                if(v[i] + v[j] == n) ret = v[i];
            }
        }
        printf("%d %d\n", ret, n - ret);
    }
    return 0;
}