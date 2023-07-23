#include<iostream>
using namespace std;

int n, m, a[104], sum, mx = 0;
int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                sum = a[i] + a[j] + a[k];
                if(sum > mx && sum <= m)
                    mx = sum;
            }
        }
    }
    cout << mx;
    return 0;
}