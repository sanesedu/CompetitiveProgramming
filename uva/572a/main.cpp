
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
    
int pet, m, n;

bool isValid(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

class UnionFind {
    
    private:
        vector<int> rank, p;
        int diff;

    public:

        UnionFind(int n, int pet) {
            rank.assign(n, 0);
            p.assign(n, 0);
            fori(i, n) p[i] = i;
            diff = pet;
        }
        
        int findSet(int i) {
            return (i == p[i]) ? i: (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if(!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);

                if(rank[x] > rank[y]) {
                    p[y] = x;
                } else {
                    p[x] = y;
                    if(rank[x] == rank[y]) ++rank[y];
                }
                --diff;
            }
        }

        int getdiff() {
            return diff;
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    while(cin >> m >> n) {
        if(m == 0) break; 
        
        vector<vector<char>> mat(m, vector<char>(n));;

        pet = 0;
        
        fori(i, m) {
            fori(j, n) {
                cin >> mat[i][j];
                if(mat[i][j] == '@') ++pet;
            }
        }

        if(pet <= 1) cout << pet << endl; 
        else {
            UnionFind uf(m*n + n, pet);
            
            fori(i, m) {
                fori(j, n) {
                    if(mat[i][j] == '@') {
                        fori(k, 8) {
                            int newx = i + dx[k];
                            int newy = j + dy[k];
                            if(isValid(newx, newy) && mat[newx][newy] == '@') {
                                uf.unionSet(i*n + j, newx*n + newy);
                            }
                        }                    
                    }
                }
            }   
            cout << uf.getdiff() << endl;
        }

    }

    return 0;
}
