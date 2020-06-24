
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1e9
#define MAX_V 38

using namespace std;

int res[MAX_V][MAX_V], mf, f, s, t;
vector<vector<int>> graph;
vector<int> p;

int total, n;
char app, pc;
bool fin = false;

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

void readInputAndSetup() {
	
    total = 0;
	
    memset(res, 0, sizeof res);
	
    graph.assign(MAX_V, vector<int>());
	
    s = 0;
	
    t = MAX_V - 1;
	
    for (int i = 27; i < MAX_V - 1; i++) {
		res[i][t] = 1;
		graph[i].push_back(t);
		graph[t].push_back(i);
	}
	
    while (true) {
	
        if (scanf("%c", &app) == EOF) {
			fin = true;
			break;
		}
		if (app == '\n') break;
		
        scanf("%d ", &n);
		
        res[0][app - 'A' + 1] = n;
		
        graph[0].push_back(app - 'A' + 1);
		graph[app - 'A' + 1].push_back(0);
		
        total += n;

		while (true) {
		
            scanf("%c", &pc);
		
            if (pc == ';') {
				scanf("%c", &pc);
				break;
			}
		
            res[app - 'A' + 1][pc - '0' + 27] = 1;
		
            graph[app - 'A' + 1].push_back(pc - '0' + 27);
			graph[pc - '0' + 27].push_back(app - 'A' + 1);
		}
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
	
            if (u == t) break;
			
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

void output() {
	
    if (total != mf) {
		printf("!\n");
	} else {
		for (int i = 27; i < 37; i++) {
			bool b = false;
			
            for (int j = 1; j <= 26; j++) {
				if (res[i][j]) {
					printf("%c", j + 'A' - 1);
					b = true;
					break;
				}
			}
			
            if (!b)	printf("_");
		}
		printf("\n");
	}
}

int main() {
	
    while (true) {
		
        readInputAndSetup();
		edmondKarp();
		output();

		if (fin) break;
	}

	return 0;
}
