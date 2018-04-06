// fast solution
#include <stdio.h>
typedef long long LL;
#define M 10001
const int maxn = 100 + 5;
int x[maxn*2];

// 扩展欧几里得算法
void gcd(LL a, LL b, LL &d, LL &x, LL &y) {
    if(!b) {
        d = a; x = 1; y = 0;
    } else {
        gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 2*n; i+=2) {
        scanf("%d", &x[i]);
    }
    for(LL a = 0; a <= M; a++) {
        LL d, b, k;
        gcd(a+1, M, d, b, k);
        LL c = x[3] - a*a*x[1];
        if(c % d) continue;
        b = c / d * b;
        bool falg = true;
        for(int i = 2; i <= 2*n; i+=2) {
            x[i] = (a * x[i-1] + b) % M;
            if(i+1 <= 2*n && x[i+1] != (a*x[i] + b) % M) {
                falg = false;
                break; 
            }
        }
        if(falg) break;
    }
    for(int i = 2; i <= 2*n; i+=2) {
        printf("%d\n", x[i]);
    }
    return 0;
}