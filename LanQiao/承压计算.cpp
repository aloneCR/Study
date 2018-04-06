#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 29;
double a[maxn + 5][maxn + 5];
int main() {
    freopen("data.in", "r", stdin);
    int n = 29;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            a[i+1][j] += a[i][j] / 2;
            a[i+1][j+1] += a[i][j] / 2;
        }
    }
    double minv = INF, maxv = 0.0;
    for(int i = 1; i <= 30; i++) {
        minv = min(minv, a[30][i]);
        maxv = max(maxv, a[30][i]);
    }
    printf("%.3f %.3f %.3f\n", minv, maxv, maxv/minv*2086458231);
    return 0;
}