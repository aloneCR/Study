//#define LOCAL
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 20 + 5;
char mp[maxn][maxn];
int vis[maxn][maxn][1 << 11];
int n, m, t;

typedef struct State {
    int step;
    int x, y;
    int keys;// 二进制压缩表示获取钥匙的情况
    State() {}
    State(int x, int y, int step, int keys): x(x), y(y), step(step), keys(keys) {}
} sta;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int bfs(int x, int y) {
    memset(vis, 0, sizeof(vis));
    queue<State> q;
    vis[x][y][0] = 1;
    q.push(State(x, y, 0, 0));
    while(!q.empty()) {
        sta p = q.front();
        q.pop();
        if(p.step >= t) continue;
        if(mp[p.x][p.y] == '^') return p.step;
        for(int i = 0; i < 4; i++) {
            x = p.x + dx[i], y = p.y + dy[i];
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(mp[x][y] == '*') continue;
            sta a = p;
            a.x = x;
            a.y = y;
            a.step = p.step + 1;
            if(mp[x][y] >= 'a' && mp[x][y] <= 'j') {
                int ch = mp[x][y] - 'a';
                a.keys = p.keys | (1 << ch);
            } else if(mp[x][y] >= 'A' && mp[x][y] <= 'J') {
                int ch = mp[x][y] - 'A';
                if(!(p.keys & (1 << ch))) continue;
            }
            if(!vis[a.x][a.y][a.keys]) {
                vis[a.x][a.y][a.keys] = 1;
                q.push(a);
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
	freopen("/home/lxp/Study/data.in", "r", stdin);
#endif
    while(scanf("%d%d%d", &n, &m, &t) == 3) {
        for(int i = 0; i < n; i++) scanf("%s", mp[i]);
        int sx, sy;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mp[i][j] == '@') printf("%d\n", bfs(i, j));
    }
    return 0;
}
