#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;
const int maxn = 300 + 5;
int dp[maxn][maxn][maxn];

int solve(int n, int k, int lim) {
    if(n == 0) return 1;
    if(n > 0 && k == 0) return dp[n][k][lim] = 0;
    if(dp[n][k][lim] != -1) return dp[n][k][lim];

    dp[n][k][lim] = 0;
    for(int i = 1; i <= min(lim, n); i++) {
        dp[n][k][lim] += solve(n - i, k - 1, i);
    }
    return dp[n][k][lim];
}

int main() {
    int n, k;
    while(scanf("%d%d", &n, &k) == 2) {
        memset(dp, -1, sizeof(dp));
        k = min(n, k);
        printf("%d\n", solve(n, k, n));
    }
    return 0;
}