
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1e17

using namespace std;

map<string, long long> ids;
map<long long, set<long long>> graph;
map<long long, bool> visited;

void printMap() {
    
    map<string, long long>::iterator it;

    for(it = ids.begin(); it != ids.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

}

void printGraph() {
    
    map<long long, set<long long>>::iterator it;

    for(it = graph.begin(); it != graph.end(); ++it) {
        cout << it->first << " ";
        
        set<long long>::iterator jit;
        for(jit = (it->second).begin(); jit != (it->second).end(); ++jit) {
            cout << *jit << " ";
        } 
        cout << endl;
    }
}

long long bfs(long long ini, long long goal) {

    long long level = 0;

    visited[ini] = true;

    queue<long long> q;
    queue<long long> temp;
    q.push(ini);
    temp.push(ini);

    while(!temp.empty()) {
         
        while(!temp.empty()) {
            long long t = temp.front();
            q.push(t);
            temp.pop(); 
        } 

        while(!q.empty()) {
            long long aux = q.front();
            visited[aux] = true;
            q.pop();
            if(aux == goal) {
                return level;
            }
            set<long long>::iterator it;

            for(it = graph[aux].begin(); it != graph[aux].end(); ++it) {
                if(!visited[*it]) {
                    temp.push(*it);
                }
            }
        }

        ++level;
    }

    return INF;
}

void resetVis() {
    
    map<long long, bool>::iterator it;

    for(it = visited.begin(); it != visited.end(); ++it) {
        it->second = false;
    }    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long q, n, p, commas, id;
    string temp, names, test;
    cin >> q;

    ids["Erdos, P."] = 0;
    id = 1;

    fori(i, q) {
        cin >> n >> p;

        fori(j, n+1) {
            getline(cin, temp);
            names = temp.substr(0, temp.find(":"));
            
            vector<string> nameArr;
            istringstream f(names);
            string s, prev;   
            bool app = false;

            while (getline(f, s, ',')) {
                if(app) {
                    prev += ",";
                    prev += s;
                    prev.erase(prev.begin(), std::find_if(prev.begin(), prev.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
                    nameArr.pb(prev);
                }
                prev = s;
                app = !app;
            }   

            vector<string>::iterator it, jit;

            for(it = nameArr.begin(); it != nameArr.end(); ++it) {
                if(ids.find(*it) == ids.end()) {
                    ids[*it] = id++;
                }
                for(jit = nameArr.begin(); jit != nameArr.end(); ++jit) {
                    if(ids.find(*jit) == ids.end()) {
                        ids[*jit] = id++;
                    }
                    if(*it != *jit) {
                        graph[ids[*it]].insert(ids[*jit]); 
                        graph[ids[*jit]].insert(ids[*it]); 
                    }
                } 
            }
        }

//        printMap();
//        printGraph();
        cout << "Scenario " << i+1 << endl;

        while(p--) {
            getline(cin, test);
            cout << test << " ";
            if(ids.find(test) == ids.end()) {
                cout << "infinity" << endl;
                continue;
            }
            long long res = bfs(0, ids[test]);
            if(res == INF) {
                cout << "infinity" << endl;
            } else {
                cout << res << endl;
            }
            resetVis();
        }
    }

    return 0;
}
