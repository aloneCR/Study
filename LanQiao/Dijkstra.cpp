#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1000 + 5;
struct Edge {
	int from, to, dist;
	Edge(int u, int v, int d):from(u),to(v),dist(d){}
};

struct Dijkstra{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];

	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	} 

	void AddEdge(int from, int to, int dist) {
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m-1);
	}

	struct HeapNode {
		int d, u;
		HeapNode(){}
		HeapNode(int d, int u):d(d),u(u){}
		bool operator < (const HeapNode& rhs) const {
			return d > rhs.d;
		}
	};

	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		for(int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push(HeapNode(0, s));
		while(!Q.empty()) {
			HeapNode x = Q.top(); Q.pop();
			int u = x.u;
			if(done[u]) continue;
			done[u] = true;
			for(int i = 0; i < G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push(HeapNode(d[e.to], e.to));
				}
			}
		}
	}
};

bool bellman_ford(int s) {
	queue<int> Q;
	memset(inq, 0, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++) d[i] = INF;
	d[s] = 0;
	Q.push(s);
	inq[s] = true;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		inq[u] = false;
		for(int i = 0; i < G[u].size(); i++) {
			Edge& e = edges[G[u][i]];
			if(d[u] < INF && d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				p[e.to] = G[u][i];
				if(!inq[e.to]) {
					Q.push(e.to);
					inq[e.to] = true;
					if(++cnt[e.to] > n) return false;
				}
			}
		}
	}
	return true;
}

int main() {
	
	return 0;
}
