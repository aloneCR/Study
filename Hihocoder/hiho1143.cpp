#include <stdio.h>
#define MOD 19999997

struct A {
    int x[2][2];
    A() {}

};

A getOne() {
    A a;
    a.x[0][0] = 1;
    a.x[0][1] = 0;
    a.x[1][0] = 0;
    a.x[1][1] = 1;
    return a;
}

A mul(A a, A b) {
    A c;
    for(int i = 0; i < 2; i++) {
        for(int k = 0; k < 2; k++) {
            long long ret = 0;
            for(int j = 0; j < 2; j++) {
                ret = (ret + (long long)a.x[i][j] * b.x[j][k]) % MOD;
            }
            c.x[i][k] = (int)ret;
        }
    }
    return c;
}

A pow_mod(A a, int n, int m) {
    if(n == 1) return a;
    A x = pow_mod(a, n / 2, m);
    A ans = mul(x, x);
    if(n % 2 == 1) ans = mul(ans, a);
    return ans;
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        A a;
        a.x[0][0] = 0;
        a.x[0][1] = 1;
        a.x[1][0] = 1;
        a.x[1][1] = 1;
        A ret = pow_mod(a, n, MOD);
        printf("%d\n", ret.x[1][1]);
    }
    return 0;
}