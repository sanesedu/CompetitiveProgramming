
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 260

using namespace std;
    
char img[N][N];
    
int m, n;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool isValid(int newy, int newx) {
    return (newy >= 0 && newy < n && newx >= 0 && newx < m);
}

void bfs(int y, int x, char n) {
    
    queue<pair<int, int>> q;
    q.push({y, x});

    char c = img[y][x];
   
    if(c == n) return;    

    img[y][x] = n;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        fori(k, 4) {
            int newy = cur.first + dy[k];
            int newx = cur.second + dx[k]; 
            
            if(!isValid(newy, newx)) continue;

            if(img[newy][newx] == c) {
                q.push({newy, newx});
                img[newy][newx] = n;
            }
        }
    }
}

void print() {
    fori(i, n) {
        fori(j, m) {
            cout << img[i][j];
        }
        cout << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string line;

    char c;

    while(getline(cin, line)) {
        stringstream ss(line);
    
        ss >> c;
    
        if(c == 'I') {
            ss >> m >> n;

            fori(i, n) {
                fori(j, m) {
                    img[i][j] = 'O';
                }
            }
        } else if(c == 'C') {
            fori(i, n) {
                fori(j, m) {
                    img[i][j] = 'O';
                }
            }
        } else if(c == 'L') {
            int x, y;
            char t;
            ss >> x >> y >> t;
            --x;
            --y;
            img[y][x] = t;
        } else if(c == 'V') {
            int x, y1, y2;
            char t;
            ss >> x >> y1 >> y2 >> t;
            --x;
            --y1;
            --y2;
            
            if(y2 < y1) {
                int tmp = y2;
                y2 = y1;
                y1 = tmp;
            }

            for(int k = y1; k <= y2; ++k) {
                img[k][x] = t;
            } 
        } else if(c == 'H') {
            int x1, x2, y;
            char t;
            ss >> x1 >> x2 >> y >> t;
            --x1;
            --x2;
            --y;
            
            if(x2 < x1) {
                int tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            
            for(int k = x1; k <= x2; ++k) {
                img[y][k] = t;
            } 
        } else if(c == 'K') {
            int x1, x2, y1, y2;
            char t;
            ss >> x1 >> y1 >> x2 >> y2 >> t;
            --x1;
            --x2;
            --y1;
            --y2;
            
            if(y2 < y1) {
                int tmp = y2;
                y2 = y1;
                y1 = tmp;
            }
            
            if(x2 < x1) {
                int tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            
            for(int h = y1; h <= y2; ++h) {
                for(int k = x1; k <= x2; ++k) {
                    img[h][k] = t;
                }
            } 
        } else if(c == 'F') {
            int x, y;
            char t;
            ss >> x >> y >> t; 
            --x;
            --y;
            bfs(y, x, t);
        } else if(c == 'S') {
            string name;
            ss >> name;
            cout << name << endl;
            print();        
        } else if(c == 'X') {
            break;
        }
    }

    return 0;
}
