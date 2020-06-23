
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

map<int, vector<int>> graph;

void kick(set<int> s) {

    map<int, vector<int>>::iterator it;

    for(it = graph.begin(); it != graph.end(); ++it) {
        if(s.find(it->first) != s.end()) {
           cout << "erasing " << it->first << endl;
           graph.erase(it->first);
       } else {

            set<int>::iterator sit;
            vector<int>::iterator nit;

            for(sit = s.begin(); sit != s.end(); ++sit){
                //graph[it->first].erase(remove(graph[it->first].begin(), graph[it->first].end(), *sit), graph[it->first].end());
                nit = find(graph[it->first].begin(), graph[it->first].end(), *sit);
                if(nit != graph[it->first].end()) {
                    graph[it->first].erase(nit);
                    --sit;
                }
                cout << "erasing from vector" << endl;
            }
       }
    }

    s.clear();

}

set<int> get_reps() {

    set<int> s;

    map<int, vector<int>>::iterator it;

    for(it = graph.begin(); it != graph.end(); ++it) {
        if(graph[it->first].size() == 1) {
            cout << it->first << endl;
            s.insert(it->first);
        }
    }

    return s;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, m, a, b;
    cin >> n >> m;

    fori(i, m) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    set<int> res = get_reps();
    
    cout << "reps1" << endl;

    int count = 0;

    while(res.size() > 1) {
        ++count;
        kick(res);
        cout << "kick" << endl;
        res = get_reps();
    }

    cout << count << endl;

    return 0;
}
