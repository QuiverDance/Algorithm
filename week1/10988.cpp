#include<iostream>
#include<string>

using namespace std;

int main(void){
    string str;
    cin >> str;

    int size = str.size();
    int pivot = size / 2;
    if(size % 2 == 0){
        for(int i = 0; i < pivot; i++){
            if(str[pivot-i-1] != str[pivot+i]){
                cout << 0;
                return 0;
            }
        }
    }
    else{
        for(int i = 1; i <= pivot; i++){
            if(str[pivot-i] != str[pivot+i]){
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;
    return 0;
}