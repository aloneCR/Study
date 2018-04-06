#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100000 + 5;
int par[maxn];
map<string, int> Hash;
int id;

int getId(string s) {
    if(!Hash.count(s)) {
        Hash[s] = id;
        par[id] = id;
        id++;
    }
    return Hash[s];
}

int findRoot(int x) {
    return x == par[x] ? x : par[x] = findRoot(par[x]);
}

int main() {
    int n, tag;
    string a, b;
    while(scanf("%d", &n) == 1) {
        Hash.clear();
        id = 0;
        for(int i = 0; i < n; i++) {
            cin >> tag >> a >> b;
            int x = findRoot(getId(a));
            int y = findRoot(getId(b));
            if(tag == 0) {
                par[x] = y;
            } else {
                printf("%s\n", x == y ? "yes":"no");
            }
        }
    }
    return 0;
}