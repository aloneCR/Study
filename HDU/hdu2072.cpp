#include <stdio.h>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
const int maxn = 1000000 + 5;
map<string, int> Hash;
int main() {
    string line, s;
    while(getline(cin, line) && line[0] != '#') {
        Hash.clear();
        int ans = 0;
        stringstream  ss(line);
        while(ss >> s) {
            if(!Hash.count(s)) {
                ans++;
                Hash[s] = 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}