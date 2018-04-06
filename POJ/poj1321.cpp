#include <stdio.h>
#include <string.h>
const int maxn = 8 + 5;
int col[maxn];
char chess[maxn][maxn];
int ret, n, k;

void dfs(int x, int d) {
    if(d > k) {
        ++ret;
        return;
    }
    for(int i = x; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(chess[i][j] == '#' && !col[j]) {
                col[j] = 1;
                dfs(i+1, d+1);
                col[j] = 0;
            }
        }
    }
}

int main() {
    while(scanf("%d%d", &n, &k) == 2 && n > 0) {
        memset(col, 0, sizeof(col));
        ret = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", chess[i]);
        }
        dfs(0, 1);
        printf("%d\n", ret);
    }
    return 0;
}