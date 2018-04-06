#include <stdio.h>
const int maxn = 60;
int a[maxn];
int main() {
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    for(int i = 5; i < 55; i++) {
        a[i] = a[i-1] + a[i-3];
    }
    int n;
    while(scanf("%d", &n) == 1 && n) {
        printf("%d\n", a[n]);
    }
    return 0;
}