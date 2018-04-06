#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
const int maxn = 1000000 + 5;
int prim[maxn], e[maxn], check[maxn];
int tol;

void getPrimes(int n) {
    tol = 0;
    memset(check, 0, sizeof(check));
    for(int i = 2; i <= n; i++) {
        if(!check[i]) prim[tol++] = i;
        for(int j = 0; j < tol; j++) {
            if(i * prim[j] > n) {
                break;
            }
            check[i * prim[j]] = 1;
            if(i % prim[j] == 0) {
                break;
            }
        }
    }
}

void add_integer(int n, int d) {
    for(int i = 0; i < tol; i++) {
        while(n % prim[i] == 0) {
            n /= prim[i];
            e[i] += d;
        }
        if(n == 1) break;
    }
}

void add_factorial(int n, int d) {
    for(int i = 2; i <= n; i++) {
        add_integer(i, d);
    }
}

int main() {
    getPrimes(1000000);
    int p, q, r, s;
    while(scanf("%d%d%d%d", &p, &q, &r, &s) == 4) {
        memset(e, 0, sizeof(e));
        add_factorial(p, 1);
        add_factorial(q, -1);
        add_factorial(p - q, -1);
        add_factorial(r, -1);
        add_factorial(s, 1);
        add_factorial(r - s, 1);
        double ret = 1;
        for(int i = 0; i < tol; i++) {
            ret *= pow(prim[i], e[i]);
        }
        printf("%.5f\n", ret);
    }
    return 0;
}