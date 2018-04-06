#include <stdio.h>
#include <math.h>
#include <string.h>
const int maxn = 65536 + 5;

int main() {
    int n, kase = 0;
    while(scanf("%d", &n) == 1 && n > 0) {
        kase++;
        if(kase > 1) printf("\n");
        printf("Case %d.\n", kase);
        for(int i = 2; i <= sqrt(n); i++) {
            int t = 0;
            while(n % i == 0) {
                t++;
                n /= i;
            }
            if(t) printf("%d %d ", i, t);
            if(n == 1) break;
        } 
        if(n != 1) printf("%d %d ", n, 1);
        printf("\n");
    }
    return 0;
}