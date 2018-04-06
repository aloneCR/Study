#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;
const int maxn = 10 + 5;
const int goal = (2 << 10) - 1;
int mp[maxn][maxn];
bool v[maxn][maxn][(2 << 10) + 5];

typedef struct Statu {
    int x, y;
    int step;
    int keys;
    Statu() {}
    Statu(int x, int y, int step, int keys): x(x), y(y), step(step), keys(keys) {}
} sta;

const int dx[] = {0, 0, -1, 1};
const int dy[] = { -1, 1, 0, 0};

int bfs() {
    memset(v, 0, sizeof(v));
    v[0][0][0] = 1;
    queue<Statu> q;
    q.push(sta(0, 0, 0, 0));
    while(!q.empty()) {
        sta p = q.front();
        q.pop();
        if(p.x == 0 && p.y == 0 && p.keys == goal) {
            return p.step;
        }
        if(p.x == 9 && p.y == 6 ) printf("found\n");
        //printf("%d %d %d\n", p.x, p.y, p.keys);
        for(int i = 0; i < 4; i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if(x < 0 || y < 0 || x >= 10 || y >= 10) continue;
            if(mp[x][y] == -1) continue;

            int keys = p.keys;
            if(mp[x][y] == 0) {
                keys = p.keys;
            } else {
                keys = p.keys | (2 << (mp[x][y] - 1));
            }
            if(!v[x][y][keys]) {
                v[x][y][keys] = 1;
                q.push(sta(x, y, p.step + 1, keys));
            }
        }
    }
    return -1;
}

int main() {
    freopen("data.in", "r", stdin);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            scanf("%d", &mp[i][j]);
            //printf("%4d", mp[i][j]);
        }
        //printf("\n");
    }

    printf("%d\n", bfs());

    return 0;
}