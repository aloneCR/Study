#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10000 + 5;
int r[maxn], tol;

int x[20];

int getLen(int a) {
    int ret = 0;
    while(a > 0) {
        x[ret++] = a % 10;
        a /= 10;
    }
    int low = 0, high = ret - 1;
    while( low < high) {
        swap(x[low], x[high]);
        low++;
        high--;
    }
    return ret;
}

bool isPrime(int a) {
    for(int i = 2; i <= sqrt(a); i++) {
        if(a % i == 0) return false;
    }
    return true;
}

void solve() {
    tol = 0;
    for(int i = 2; i < 10; i++) {
        if(isPrime(i)) {
            r[tol++] = i;
            //printf("%d\n", i);
        }
    }
    r[tol++] = 11;
    //printf("11\n");
    for(int i = 1; i < 1000; i++) {
        //偶数
        // int len = getLen(i), w = 0;
        // for(int j = 2 * len - 1, k = 0; j >= len; j--, k++) x[j] = x[k];
        // for(int j = 0; j < len * 2; j++) {
        //     w = w * 10 + x[j];
        // }
        // if(isPrime(w)) {
        //     r[tol++] = w;
        //     //printf("%d\n", w);
        // }
        //奇数
        int len = getLen(i), w = 0;
        for(int p = 0; p < 10; p++) {
            w = 0;
            x[len] = p;
            for(int j = 2 * len, k = 0; j > len; j--, k++) x[j] = x[k];
            for(int j = 0; j <= len * 2; j++) {
                w = w * 10 + x[j];
            }
            if(isPrime(w)) {
                if(w <= 100000000) r[tol++] = w;
                //printf("%d\n", w);
            }
        }
    }
    for(int i = 0; i < tol; i++) printf("%d\n", r[i]);
}

int main() {
    //freopen("data.in", "r", stdin);
    freopen("data2.out", "w", stdout);
    solve();
    //printf("%d\n", tol);
    int a, b;
    // while(scanf("%d%d", &a, &b) == 2) {
    //     for(int i = 0; i < tol; i++) {
    //         if(r[i] >= a && r[i] <= b) printf("%d\n", r[i]);
    //     }
    //     printf("\n");
    // }
    return 0;
}