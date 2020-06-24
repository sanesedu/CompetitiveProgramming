
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

unordered_map<string, long long> ids; //translation from author name to given id
unordered_map<long long, unordered_set<long long>> graph; //adjacency list of graph
vector<bool> visited; //visited ids
vector<long long> memo; //stores the level for each corresponding id

/*void printMemo() {

    vector<long long>::iterator it;

    long long i = 0;

    for(it = memo.begin(); it != memo.end(); ++it) {
        cout << i << " " << *it << endl;
        ++i;
    }
    cout << endl;
}

void printMap() {
    
    unordered_map<string, long long>::iterator it;

    for(it = ids.begin(); it != ids.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

void printGraph() {
    
    unordered_map<long long, unordered_set<long long>>::iterator it;

    for(it = graph.begin(); it != graph.end(); ++it) {
        cout << it->first << " ";
        
        unordered_set<long long>::iterator jit;
        for(jit = (it->second).begin(); jit != (it->second).end(); ++jit) {
            cout << *jit << " ";
        } 
        cout << endl;
    }
    cout << endl;
}*/

void bfs(long long ini) {

    long long level = 0; //current level

    visited[ini] = true;

    queue<long long> q;
    q.push(ini);

    long long curr = 1; //current level size
    long long next = 0; //next level size

    while(!q.empty()) {

        long long aux = q.front();
        visited[aux] = true;

        if(level < memo[aux]){ //we store the best possible level in the memo table
            memo[aux] = level;
        }

        q.pop();
        
        unordered_set<long long>::iterator it;

        for(it = graph[aux].begin(); it != graph[aux].end(); ++it) {
            if(!visited[*it]) {
                q.push(*it);
                ++next; 
            }
        }
        
        --curr;

        if(curr == 0) { //we have finished the analysis of the current level
            ++level;
            curr = next;
            next = 0;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long q, n, p, id;
    string temp, names, test;
    cin >> q;

    fori(i, q) {

        cin >> n >> p;

        ids["Erdos, P."] = 0;

        id = 1;

        fori(j, n+1) {

            getline(cin, temp);

            names = temp.substr(0, temp.find(":")); //remove title
            
            vector<string> nameArr;
            
            istringstream f(names);
            
            string s, prev;   
            
            bool app = false; //false: surname (dont add), true: name (add)

            while (getline(f, s, ',')) { //get string up to next comma
                if(app) { 
                    prev += ","; //surname + ,
                    prev += s; //surname, + name
                    prev.erase(prev.begin(), std::find_if(prev.begin(), prev.end(), std::bind1st(std::not_equal_to<char>(), ' '))); //erase leading spaces
                    nameArr.pb(prev); //add new author to the nameArr
                }
                prev = s;
                app = !app;
            }   

            vector<string>::iterator it;
            unordered_set<long long> tempids;

            for(it = nameArr.begin(); it != nameArr.end(); ++it) {
                if(ids.find(*it) == ids.end()) { //author not yet processed
                    ids[*it] = id++; //give new author next id
                }
                tempids.insert(ids[*it]);
            }

            for(it = nameArr.begin(); it != nameArr.end(); ++it) {
                tempids.erase(ids[*it]);
                graph[ids[*it]].insert(all(tempids)); //add all ids except itself to graph of current id
                tempids.insert(ids[*it]);
            }
        }
        
        visited.resize(id);
        fill(all(visited), false);
  
 //       printMap();
   //     printGraph();
  
        memo.resize(id);
        fill(all(memo), INF); 
        
      //  printMemo();
        
        bfs(0); //get level for every author
        
//        printMemo();
        cout << "Scenario " << i+1 << endl;

        while(p--) {

            getline(cin, test);
            
            cout << test << " ";
            
            if(ids.find(test) == ids.end()) { //if author has not appeared on given scenario
                cout << "infinity" << endl;
                continue;
            }
            
            long long res = memo[ids[test]]; 
            
            if(res == INF) {
                cout << "infinity" << endl;
            } else {
                cout << res << endl;
            }
        }
        //clear used data structures 
        memo.clear();
        graph.clear();
        visited.clear();
        ids.clear();
    }

    return 0;
}
