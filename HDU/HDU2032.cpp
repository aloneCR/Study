#include <stdio.h>
const int maxn = 30 + 5;
int a[maxn][maxn];

void solve(int n) {
    a[1][1] = 1;
    printf("1\n");
    for(int i = 2; i <= n; i++) {
        a[i][1] = a[i][i] = 1;
        for(int j = 2; j < i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
        for(int j = 1; j <= i; j++) {
            printf("%d%c", a[i][j], j==i?'\n':' ');
        }
    }
    printf("\n");
}
int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        solve(n);
    }
    return 0; 
}