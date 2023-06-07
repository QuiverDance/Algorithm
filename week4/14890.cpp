#include<iostream>

using namespace std; 

int n, l, board1[104][104], board2[104][104], ret; 

void solve(int a[104][104]){
    for(int i = 0; i < n; i++){
        int cnt = 1; 
        int j;  
        for(j = 0; j < n - 1; j++){
            if(a[i][j] == a[i][j + 1])cnt++; 
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1; 
            else if(a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; 
            else break;
        }
        if(j == n - 1 && cnt >= 0) ret++; 
    }
    return; 
} 

int main(){
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            scanf("%d", &board1[i][j]); 
            board2[j][i] = board1[i][j];
        }
    }    
    solve(board1); solve(board2);  
    printf("%d\n", ret);  
    return 0; 
}