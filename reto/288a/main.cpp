
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    
bool some;

class UnionFind {
    
    private: 
        vector<int> p, rank;
        int maxrank;

    public:

        UnionFind(int n) {
            rank.assign(n, 1);
            p.assign(n, 0);
            fori(i, n) p[i] = i;
            maxrank = 1;
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void join(int i, int j) {
            if(!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);
             
                if(rank[x] > rank[y]) {
                    p[y] = x;
                    rank[x] += rank[y];
                    if(rank[x] > maxrank) maxrank = rank[x];
                } else {
                    p[x] = y;
                    rank[y] += rank[x];
                    if(rank[y] > maxrank) maxrank = rank[y];
                }
            }
        }

        int getmax() {
            if(some) return maxrank;
            else return 0;
        }
};

bool isValid(int x, int y, int c, int f) {
    
    return ((x >= 0) && (x < f) && (y >= 0) && (y < c));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int f, c, tx, ty, n, a, b;

    string s;

    while(cin >> f >> c) {
        vector<vector<int>> mat(f, vector<int>(c, 0));
      
        some = false;

        getline(cin, s);
        
        for(int i = 0; i < f; ++i) {
            getline(cin, s);
            for(int j = 0; j < c; ++j) {
                if(s[j] == '#') {
                    mat[i][j] = 1;
                    some = true;
                }
            } 
        }

        UnionFind uf(f*c+c);

        for(int i = 0; i < f; ++i) {
            for(int j = 0; j < c; ++j) {
                if(mat[i][j] == 1) {
                    fori(k, 8) {
                        tx = i + dx[k];
                        ty = j + dy[k];
                        if(isValid(tx, ty, c, f) && mat[tx][ty] == 1) {
                            uf.join(i*c + j, tx*c + ty);    
                        }
                    } 
                }    
            }
        }
        
        cout << uf.getmax();        
        
        cin >> n;

        while(n--) {
            cin >> a >> b;
            a--;
            b--;
            mat[a][b] = 1; 
            some = true;
            fori(k, 8) {
                tx = a + dx[k];
                ty = b + dy[k];
                if(isValid(tx, ty, c, f) && mat[tx][ty] == 1) {
                    uf.join(a*c + b, tx*c + ty);    
                }
            } 
            cout << " " << uf.getmax();        
        }
        cout << endl;
    }

    return 0;
}
