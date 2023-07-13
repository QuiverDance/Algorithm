#include<iostream>
using namespace std;

int n;
int main(void){
    cin >> n;
    for(int i = 0; i < n / 4; i++)
        cout << "long ";
    cout << "int";
    return 0;
}