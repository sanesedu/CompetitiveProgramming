
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1e9
#define MAX_V 110

using namespace std;

int n, s, t, c, a, b, w, mf, f;

int res[MAX_V][MAX_V];

vector<vector<int>> graph;

vector<int> p;

void augment(int v, int minEdge) {

    cout << "here" << endl;

    if(v == s) {
        f = minEdge; //store minEdge in global variable f
        return;
    } else if(p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; 
        res[v][p[v]] += f; 
        cout << "backtracking" << endl;
    }
}

void print() {
    fori(i, n) {
        fori(j, n) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printv() {
    fori(i, n) {
        cout << p[i] << " ";
    }
    cout << endl;
    cout << endl;
}

void edmondKarp(int n) {

    mf = 0;
    
    while(1) {

        print();

        f = 0;
        
        vector<bool> visited(MAX_V, false);
        visited[s] = true;

        queue<int> q;
        q.push(s);
    
        p.assign(MAX_V, -1); //store BFS spanning tree from s -> t
    
        while(!q.empty()) {
            
            int u = q.front();
            q.pop();

            if(u == t) break; //stop BFS if we find sink

            vector<int>::iterator it;
            for(it = graph[u].begin(); it != graph[u].end(); ++it) {
                if(res[u][*it] > 0 && !visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                    p[*it] = u;
                }
            }

            cout << "t: " << t << endl;
            cout << "s: " << s << endl;
            printv();
            augment(t, INF); //find min edge weigth 'f' in this path
        
            if(f == 0) break; //we cannot send any more flow
            else mf += f; //we can still send flow -> increase maxflow
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int index = 1;

    while(cin >> n) {
      
        if(n == 0) break;  

        memset(res, 0, sizeof(res));
        graph.assign(n, vector<int>());

        cin >> s >> t >> c;      
        --s;
        --t;

        cout << "st: " << s << " " << t << endl;
        
        fori(i, c) {
            cin >> a >> b >> w;
            --a;
            --b; 
            res[a][b] += w;
            res[b][a] += w; 
            graph[a].pb(b);
            graph[b].pb(a);
        }
        
        edmondKarp(n);

        cout << "Network " << index << endl;
        cout << "The bandwith is " << mf << "." << endl;
        ++index; 
    }

    return 0;
}
