#include <stdio.h>
#include <string.h>
const int maxn = 9 + 5;
int a[maxn][maxn];


bool dfs(int x, int y) {
    //printf("%d %d\n", x, y);
    if(x >= 9) { //find answer
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        return true;
    }
    if(a[x][y] != 0) {
        int f;
        if(y == 8) {
            f = dfs(x + 1, 0);
        } else {
            f = dfs(x, y + 1);
        }
        if(f) return true;
        return false;
    }
    bool used[maxn]; //行、列、九宫
    memset(used, 0, sizeof(used));
    //check row and col
    for(int i = 0; i < 9; i++) {
        used[a[x][i]] = 1;
        used[a[i][y]] = 1;
    }
    //check 3*3
    int sx = x / 3 * 3, sy = y / 3 * 3;
    //printf("%d %d\n", sx, sy);
    for(int i = sx; i < sx + 3; i++)
        for(int j = sy; j < sy + 3; j++) {
            used[a[i][j]] = 1;
        }
    for(int i = 1; i <= 9; i++) {
        if(!used[i]) {
            int f;
            a[x][y] = i;
            printf("%d %d %d\n", x, y, i);
            if(y == 8) {
                f = dfs(x + 1, 0);
            } else {
                f = dfs(x, y + 1);
            }
            a[x][y] = 0;
            if(f) return true;
        }
    }
    return false;
}

int main() {
    freopen("data.in", "r", stdin);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &a[i][j]);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    bool f = dfs(0, 0);
    //printf("%d\n", f);
    return 0;
}
/*
1 2 6 7 3 4 5 9 8 
3 7 8 5 9 2 6 1 4 
4 9 5 1 6 8 2 3 7 
7 3 9 4 2 5 1 8 6 
8 6 1 3 7 9 4 2 5 
2 5 4 8 1 6 3 7 9 
5 4 7 2 8 1 9 6 3 
6 1 3 9 5 7 8 4 2 
9 8 2 6 4 3 7 5 1 
*/