/*
    #11403 경로 찾기
*/
#include<iostream>
#define INF 1e9
using namespace std;

int n, a[104][104];
int main(){
    fill(&a[0][0], &a[0][0] + 104 * 104, INF);
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num != 0) a[i][j] = 1;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                 a[i][j] = min(a[i][j], a[i][k] + a[k][j]);       
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != INF) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << '\n';
    }
    return 0;
}