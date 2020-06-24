
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1e9
#define MAX_V 105

using namespace std;

int res[MAX_V][MAX_V], mf, f, s, t;
vector<vector<int>> graph;
vector<int> p;

int n, c, cnt = 1;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void edmondKarp() {
	
    mf = 0;
	
    while (1) {
	
        f = 0;
	
        bitset<MAX_V> visited;
		visited.set(s);
	
        queue<int> q;
		q.push(s);
	
        p.assign(MAX_V, -1);
	
        while (!q.empty()) {
	
            int u = q.front();
			q.pop();
	
            if (u == t)	break;
	
            for (int i = 0; i < (int) graph[u].size(); i++) {
				int v = graph[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}

		augment(t, INF);
		
        if (f == 0)	break;
        else mf += f;
	}
}

int main() {

	while (scanf("%d", &n) == 1) {
	    
        if(n == 0) break;

        memset(res, 0, sizeof res);
		graph.assign(n, vector<int>());

		scanf("%d %d %d", &s, &t, &c);
		s--;
		t--;

		for (int i = 0; i < c; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--;
			v--;
			res[u][v] += w;
			res[v][u] += w;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		edmondKarp();

		printf("Network %d\nThe bandwidth is %d.\n\n", cnt++, mf);
	}

	return 0;
}
