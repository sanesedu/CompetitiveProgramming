
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

bool eq(string a, string b) {
    if(a.size() == b.size()) {
        int c = 0;
        for(int i = 0; i < (int) a.size(); ++i) {
            if(a[i] != b[i]) {
                c++;
                if(c > 1) return false;
            }
        }
        return true;
    }
    return false;
}

map<string, int> level;

int bfs(map<string, vector<string>> map, string s, string d) {
    
    queue<string> q;
    vector<string> visited;
    
    q.push(s);
    level[s] = 0;
    visited.pb(s);

    while(!q.empty()) {
        string cur = q.front();
        q.pop();

        if(cur == d) {
            return level[d];
        }

        for(int i = 0; i < (int) map[cur].size(); ++i) {
            if(find(all(visited), map[cur][i]) == visited.end()) {
                q.push(map[cur][i]);
                level[map[cur][i]] = level[cur] + 1;
                visited.pb(map[cur][i]);
            }
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;

    string word, line, source, destination;

    while(t--) {
        
        vector<string> arr;

        while(cin >> word) {
            if(word == "*") break;
            arr.pb(word);
        }

        map<string, vector<string>> map;

        for(int i = 0; i < (int) arr.size(); ++i) {
            for(int j = 0; j < (int) arr.size(); ++j) {
                if(i != j && eq(arr[i], arr[j])) {
                    map[arr[i]].pb(arr[j]);
                    map[arr[j]].pb(arr[i]);
                } 
            }
        }

        cin.ignore();

        while(getline(cin, line)) {
            
            stringstream ss(line);
            
            if(line.empty()) break;
            
            ss >> source >> destination;

            cout << source << " " << destination << " " << bfs(map, source, destination) << endl;
        }
        
        level.clear();
        
        if(t > 0) cout << endl;
    }

    return 0;
}
