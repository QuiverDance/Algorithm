#include<iostream>
using namespace std;

int a[3];
int main(void){
    for(int i = 0; i < 3; i++) cin >> a[i];
    if(a[0] + a[1] + a[2] != 180){ cout << "Error"; return 0; }
    if(a[0] == 60 && a[1] == 60 && a[2] == 60) cout << "Equilateral";
    else if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) cout << "Isosceles";
    else cout << "Scalene";
    return 0;
}