#include<iostream>
#include<string>
using namespace std;

int n, x, y, a[104][104], cnt;
int main(void){
    cin >> n;
    for(int k = 0; k < n; k++){
        cin >> x >> y;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++)
                a[i + y][j + x] = 1;
        }
    }
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++)
            if(a[i][j]) cnt++;
    }
    cout << cnt;
    return 0;
}