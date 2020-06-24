
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1e9
#define MAX_V 40

using namespace std;

int res[MAX_V][MAX_V];

vector<vector<int>> graph;

vector<int> p;

int total, n, s, mf, f, t;

char app, pc;

bool fin;

void readInput() {
    
    total = 0;

    memset(res, 0, sizeof(res));

    graph.assign(MAX_V, vector<int>());

    s = 0;

    t = MAX_V - 1;

    for(int i = 27; i < MAX_V - 1; ++i) {
        res[i][t] = 1;
        graph[i].pb(t);
        graph[t].pb(i);
    }

    while(true) {
    
        if(scanf("%c", &app) == EOF) {
            fin = true;
            break;
        }

        if(app == '\n') break;

        scanf("%d", &n);
    
        res[0][app - 'A' + 1] = n;
    
        graph[0].pb(app - 'A' + 1);
        graph[app - 'A' + 1].pb(0);
    
        total += n;

        while(true) {
            scanf("%c", &pc);
            if(pc == ';') {
                scanf("%c", &pc);
                break; 
            }
            res[app - 'A' + 1][pc - '0' + 27] = 1;
            graph[app - 'A' + 1].pb(pc - '0' + 27);
            graph[pc - '0' + 27].pb(app - 'A' + 1);
        }
    }

}

void augment(int u, int minEdge) {

    if(u == s) {
        f = minEdge;
        return;
    } else if(p[u] != -1) {
        augment(p[u], min(minEdge, res[p[u]][u]));
        res[p[u]][u] -= f;
        res[u][p[u]] += f;
    }
}

void edmondKarp() {

    mf = 0;

    while(true) {
        
        f = 0;

        bitset<MAX_V> visited;
        visited.set(s);

        queue<int> q;
        q.push(s);

        p.assign(MAX_V, -1);

        while(!q.empty()) {
            
            int u = q.front();
            q.pop();

            if(u == t) break;

            for(int i = 0; i < (int) graph[u].size(); ++i) {
                int v = graph[u][i];
                
                if(res[u][v] > 0 && !visited.test(v)) {
                    visited.set(v);
                    q.push(v);
                    p[v] = u;
                }
            }

            augment(t, INF);

            if(f == 0) break;
            else mf += f;
        }
    }
}

void printSol() {
    
    if(total != mf) {
        printf("!\n");
    } else {
        for(int i = 27; i < 37; ++i) {
            bool b = false;
            for(int j = 1; j <= 26; ++j) {
                if(res[i][j]) {
                    printf("%c", j + 'A' + 1);
                    b = true;
                    break;
                }
            }

            if(!b) printf("_");
        }
        printf("\n");
    }

}

int main() {

    while(!fin) {
        readInput();    
        edmondKarp();
        printSol();
        
        if(fin) break; 
    }

    return 0;
}
