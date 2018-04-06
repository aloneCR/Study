#include <stdio.h>
#include <math.h>
const int maxn = 1000 + 5;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) == 2) {
        double ans = n;
        double a = n;
        for(int i = 0; i < m-1; i++) {
            a = sqrt(a);
            ans += a;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}