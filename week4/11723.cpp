#include<stdio.h>

int n, set, target;
char s[10];
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %d", s, &target);
        if(s[0] == 'a' && s[1] == 'd')
            set |= (1 << target);
        else if(s[0] == 'r')
            set &= ~(1 << target);
        else if(s[0] == 'c')
            set & (1 << target) ? printf("1\n") : printf("0\n");
        else if(s[0] == 't')
            set ^= (1 << target);
        else if(s[0] == 'a')
            set = (1 << 21) - 1;
        else
            set = 0;
    }
    return 0;
}