#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;

int main() {
    LL ret = 1;
    int n = 0;
    while(scanf("%d", &n) == 1) {
        ret = 1;
        for(int i = 1; i <= n; i++) {
            ret *= i;
        }
        printf("%lld\n", ret);
    }

    return 0;
}