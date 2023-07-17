#include<iostream>
using namespace std;

int n, m, t, a[104][104];
int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t;
            cout << a[i][j] + t << " ";
        }
        cout << '\n';
    }
    return 0;
}