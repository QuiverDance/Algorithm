#include<iostream>
#include<string>

using namespace std;

int n;
int map[64][64];
string s;

bool isFill(int x1, int y1, int x2, int y2){
    int temp = map[y1][x1];
    for(int i = y1; i < y2; i++){
        for(int j = x1; j < x2; j++){
            if(map[i][j] != temp){
                return false;
            }
        }
    }
    return true;
}

void solve(int x1, int y1, int x2, int y2){
    if(isFill(x1, y1, x2, y2) || (x1 == x2) && (y1 == y2)){
        cout << map[y1][x1];
        return;
    }
    cout << "(";
    solve(x1, y1, (x1 + x2)/2, (y1 + y2)/2);
    solve((x1 + x2)/2, y1, x2, (y1 + y2)/2);
    solve(x1, (y1 + y2)/2, (x1 + x2)/2, y2);
    solve((x1 + x2)/2, (y1 + y2)/2, x2, y2);
    cout << ")";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            map[i][j] = s[j] - '0';
    }
    solve(0, 0, n, n);
    return 0;
}