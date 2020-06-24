
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;
    
int t, rows, cols, n;

pair<int, int> pos;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int y, int x) {
    return (y >= 0 && y < rows && x >= 0 && x < cols);
}

bool bfs(int i, int j, vector<vector<char>> mat, string s) {

    int len = s.length();

    pair<int, int> ini = {i, j};

    queue<pair<int, int>> q;
    q.push(ini);

    map<pair<int, int>, int> mp;

    mp[ini] = 1;

    while(!q.empty()) {
        
        pair<int, int> cur = q.front();
        q.pop();
    
        if(mp[cur] == len) return true;

        fori(i, 8) {
            int newy = cur.first + dy[i];
            int newx = cur.second + dx[i];

            if(!isValid(newy, newx)) continue;

            if(tolower(mat[newy][newx]) == tolower(s[mp[cur]])) {
                mp[make_pair(newy, newx)] = mp[cur] + 1;  
                q.push(make_pair(newy, newx));
            }
        }
    }

    return false;
}

void solve(vector<vector<char>> mat, string s) {
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(tolower(mat[i][j]) == tolower(s[0]) && bfs(i, j, mat, s)) {
                pos.first = i + 1;
                pos.second = j + 1;
                return;
            }    
        }
    } 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    cin >> t;

    string s;

    while(t--) {
        cin >> rows >> cols;

        vector<vector<char>> mat(rows, vector<char>(cols));

        fori(i, rows) {
            fori(j, cols) {
                cin >> mat[i][j];
            }
        }

        cin >> n;

        while(n--) {
            cin >> s;

            solve(mat, s);

            cout << pos.first << " " << pos.second << endl;
        }

        if(t) cout << endl;
    }

    return 0;
}
