#include <stdio.h>
int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        if(m - n > 1) {
            printf("NO\n");
        } else if(m - n == 1) {
            for(int i = 0; i < n; i++) printf("10");
            printf("1\n");
        } else {
            for(int i = 0; i < m; i++) printf("01");
            for(int i = 0; i < n-m; i++) printf("0");
            printf("\n");
        }
    }
    return 0;
}