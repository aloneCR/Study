#include <stdio.h>
const int maxn = 100000 + 5;
int a[2][maxn], cnt[2];

int main() {
    int n, d;
    scanf("%d%d", &d, &n);
    a[0][0] = d;
    cnt[0] = 1;
    int f = 0;
    for(int i = 1; i < n; i++) {
        f = 1 - f;
        cnt[f] = 0;
        for(int j = 0; j < cnt[1-f];) {
            int val = a[1-f][j], c = 1;
            j++;
            while(j < cnt[1-f] && a[1-f][j] == a[1-f][j-1]) {
                c++;
                j++;
            }
            a[f][cnt[f]++] = val;
            a[f][cnt[f]++] = c;
        }
    }
    for(int i = 0; i < cnt[f]; i++) {
        printf("%d", a[f][i] == -1 ? d : a[f][i]);
    }
    printf("\n");
    return 0;
}
