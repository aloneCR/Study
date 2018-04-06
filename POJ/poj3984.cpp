#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 10;
int a[maxn][maxn], vis[maxn][maxn];
pii pre[maxn][maxn];

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

void print(int x, int y) {
    if(x != 0 || y != 0) {
        pii t = pre[x][y];
        print(t.first, t.second);
    }
    printf("(%d, %d)\n", x, y);
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    q.push(pii(0, 0));
    vis[0][0] = 1;
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        if(p.first == 4 && p.second == 4) {
            print(4, 4);
            return;
        }
        for(int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x < 0 || y < 0 || x >= 5 || y >= 5) continue;
            if(!vis[x][y] && a[x][y] == 0) {
                vis[x][y] = 1;
                pre[x][y] = pii(p.first, p.second);
                q.push(pii(x, y));
            }
        }
    }
}

int main() {
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
    bfs();
    return 0;
}