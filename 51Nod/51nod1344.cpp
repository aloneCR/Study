#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 5;
const long long INF = 1e18;

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        long long ret = INF;
        long long sum = 0;
        int x;
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            sum += x;
            ret = min(ret, sum);
        }
        if(ret < 0) printf("%lld\n", -ret);
        else printf("0\n");
    }
    return 0;
}