#include<iostream>
using namespace std;

int a, b, c;
int main(void){
    while(true){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        int mx = max(a, max(b, c));
        if(mx >= a + b + c - mx){ cout << "Invalid\n"; continue; }
        if(a == b && b == c) cout << "Equilateral\n";
        else if (a == b || b == c || a == c) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
    return 0;
}