#include <stdio.h>
int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        int ret = 0, i, mid;
        // top
        for(i = 1, mid = n / 2 + 1; i <= n / 2 + 1; i++, mid += n) {
            ret += (2 * i - 1) * mid;
        }
        // buttom
        for(int cnt = n-2; i <= n; mid += n, i++, cnt -= 2) {
            ret += cnt * mid;
        }
        printf("%d\n", ret);
    }
    return 0;
}