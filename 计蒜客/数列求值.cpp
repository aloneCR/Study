#include <stdio.h>
const int maxn = 1000 + 5;
double c[maxn];
int main() {
    int n;
    double y, z;
    while(scanf("%d", &n) == 1) {
        scanf("%lf%lf", &y, &z);
        for(int i = 1; i <= n; i++) scanf("%lf", &c[i]);
        int bit = 0;
        double sum = 0; 
        for(int j = n; j >= 1; j--) {
            bit += 2;
            sum += bit * c[j];
        }
        printf("%.2f\n", (z - sum + n*y) / (n+1));
    }
    return 0;
}