#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50 + 5;
char a[maxn][maxn];
int vis[maxn][maxn];
int n, m;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

bool dfs(int x, int y, int px, int py) {
    vis[x][y] = -1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(nx == px && ny == py) continue;
        if(vis[nx][ny] != 1 && a[nx][ny] == a[x][y]) {
            if(vis[nx][ny] == -1) {
                vis[x][y] = 1;
                return true;
            }
            if(dfs(nx, ny, x, y)) return true;
        }
    }
    vis[x][y] = 1;
    return false;
}

int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) scanf("%s", a[i]);
        int f = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && dfs(i, j, -1, -1)) {
                    f = 1;
                    break;
                }
            }
        if(f) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}