
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int t, w, h;
pair<int, int> ini, goal;

map<pair<int, int>, int> dist;

bool isValid(int i, int j) {
    return (i >= 0 && i < h && j >= 0 && j < w);
}

void print(vector<vector<char>> res) {
    
    fori(i, h) {
        fori(j, w) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void bfs(vector<vector<char>> graph) {
    
    queue<pair<int, int>> q;
    q.push(ini);

    dist[ini] = 0;

    while(!q.empty()) {
        
        pair<int, int> u = q.front();
        q.pop();

        if(u == goal) break;

        fori(i, 4) {
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];
            if(isValid(nx, ny) && graph[nx][ny] != '#' && dist.find(make_pair(nx, ny)) == dist.end()) {
                dist[make_pair(nx, ny)] = dist[u] + 1;
                q.push(make_pair(nx, ny));
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

    while(t--) {
        cin >> w >> h;
    
        vector<vector<char>> mat(h, vector<char>(w));

        fori(i, h) {
            fori(j, w) {
                cin >> mat[i][j];
            }
        }
   
        fori(i, h) {
            fori(j, w) {
                if(mat[i][j] == 'E') {
                    ini = make_pair(i, j);
                } else if(mat[i][j] == 'P') {
                    goal = make_pair(i, j);
                } else if(isdigit(mat[i][j])) {
                    int p = mat[i][j] - '0';
                    mat[i][j] = '#';
                    fori(k, 4) {
                        forb(l, 1, p) {
                            int nx = i + l * dx[k];
                            int ny = j + l * dy[k];
                            if(isValid(nx, ny)) {
                                if(mat[nx][ny] == '#') break;
                                else mat[nx][ny] = '#';
                            }
                        }
                    }
                }
            }
        }

//        print(mat);

        dist.clear();
        bfs(mat);
        
        if(dist[goal] == 0) cout << "NO\n";
        else cout << dist[goal] << endl;
    }

    return 0;
}
