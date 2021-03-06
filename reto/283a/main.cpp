
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool some;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class UnionFind {

    private: 
        vector<int> p, rank;
        int maxrank;

    public:

        UnionFind(int n) {
            rank.assign(n, 1);
            p.assign(n, 0);
            fori(i, n) {
                p[i] = i;
            }
            maxrank = 1;
        }

        int findSet(int i) {
            return (i == p[i]) ? i : (p[i] = findSet(p[i]));
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

bool isValid(int i, int j, int r, int c) {
    return ((i >= 0) && (i < r) && (j >= 0) && (j < c));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int r, c;
    
    string s;

    while(cin >> r >> c) {
        
        getline(cin, s); 
    
        vector<vector<int>> mat(r, vector<int>(c, 0));

        some = false;

        fori(i, r) {
            getline(cin, s);
            fori(j, c) {
                if(s[j] == '#') {
                    mat[i][j] = 1;
                    some = true;
                }
            }
        }

        UnionFind uf(r*c + c);

        fori(i, r) {
            fori(j, c) {
                if(mat[i][j] == 1) {
                    fori(k, 4) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if(isValid(tx, ty, r, c) && mat[tx][ty] == 1) {
                            uf.join(i*c + j, tx*c + ty);
                        }
                    }
                }
            }
        }

        cout << uf.getmax() << endl;
    }

    return 0;
}
