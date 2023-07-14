#include<iostream>
using namespace std;

int n, m, st, ed, a[104];
int main(void){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int i = 0; i < m; i++){
        cin >> st >> ed;
        swap(a[st], a[ed]);
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";    
    return 0;
}