#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 1000 + 5;
int f[maxn][maxn*6], rep[maxn];

void init() {
    for(int n = 2; n <= 1000; n++) {
        f[n][0] = 0;
        f[n][1] = 1;
        for(int i = 2; ; i++) {
            f[n][i] = (f[n][i-1] + f[n][i-2]) % n;
            if(f[n][i-1] == 0 && f[n][i] == 1) {
                rep[n] = i - 1;
                break;
            }
        }
    }
}

int pow_mod(ULL a, ULL b, int m) {
    if(b == 0) return 1;
    int x = pow_mod(a, b / 2, m);
    int ans = x * x % m;
    if(b % 2) ans = ans * (a % m) % m;
    return ans;
}

int solve(ULL a, ULL b, int n) {
    if(a == 0 || n == 1) return 0;
    int p = pow_mod(a, b, rep[n]);
    return f[n][p];
}

int main() {
    init();
    ULL a, b;
    int n, T;
    cin >> T;
    while(T--) {
        cin >> a >> b >> n;
        cout << solve(a, b, n) << "\n";
    }
    return 0;
}
