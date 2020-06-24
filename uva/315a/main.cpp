
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int dfsnum[110];
int dfslow[110];
int dfsparent[110];
bool articulationvertex[110];

int dfscounter, dfsroot, rootchildren;

void articulationPoint(vector<vector<int>> graph, int u) {
    
    dfslow[u] = dfsnum[u] = dfscounter++;
    
    vector<int>::iterator it;

    for(it = graph[u].begin(); it != graph[u].end(); ++it) {
        
        if(dfsnum[*it] == -1) {
            dfsparent[*it] = u;
            if(u == dfsroot) rootchildren++;
        
            articulationPoint(graph, *it);

            if(u != *it && dfslow[*it] >= dfsnum[u]) {
                articulationvertex[u] =  true;
            }

            dfslow[u] = min(dfslow[u], dfslow[*it]);
        } else if(*it != dfsparent[u]) {
            dfslow[u] = min(dfslow[u], dfsnum[*it]);
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n, t, s;
    
    string line;

    while(cin >> n) {
        if(n == 0) break;

        vector<vector<int>> graph(n);

        while(cin >> s) {
            if(s == 0) break;
             
            --s;
            
            getline(cin, line);

            stringstream ss(line);

            while(!ss.eof()) {
                ss >> t;
                --t;
                graph[s].pb(t);
                graph[t].pb(s);
            }
        }

        dfscounter = 0;

        memset(dfsnum, -1, sizeof(dfsnum));
        memset(dfslow, 0, sizeof(dfslow));
        memset(dfsparent, 0, sizeof(dfsparent));
        memset(articulationvertex, 0, sizeof(articulationvertex));

        fori(i, n) {
            if(dfsnum[i] == -1) {
                dfsroot = i;
                rootchildren = 0;
                articulationPoint(graph, i);
                articulationvertex[dfsroot] = (rootchildren > 1);
            }
        }

        int res = 0;

        fori(i, n) {
            if(articulationvertex[i]) ++res;
        }

        cout << res << endl;
    }

    return 0;
}
