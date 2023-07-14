#include<iostream>
using namespace std;

int n, m, st, ed, k, a[104];
int main(void){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> st >> ed >> k;
        for(int i = st; i <= ed; i++) a[i] = k;
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}