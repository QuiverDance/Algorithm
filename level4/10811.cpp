#include<iostream>
#include<cstring>
using namespace std;

int n, m, st, ed, a[104];
int main(void){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int i = 0; i < m; i++){
        cin >> st >> ed;
        int temp[104];
        memcpy(temp, a, sizeof(a));
        for(int j = 0; j <= ed - st; j++){
            a[j + st] = temp[ed - j];
        }
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";    
    return 0;
}