
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

char mat[110][110];

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

class UnionFind {

    private:
        vector<int> rank, p;

    public:

        UnionFind(int n) {
            p.assign(n, 0);
            rank.assign(n, 1);
            fori(i, n) p[i] = i;
        }

        int findSet(int i) {
            return (i == p[i]) ? i : (p[i] = findSet(p[i]));
        }

        bool sameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void join(int i, int j) {
            if(!sameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);

                if(rank[x] > rank[y]) {
                    p[y] = x;
                    rank[x] += rank[y];
                } else {
                    p[x] = y;
                    rank[y] += rank[x];
                }
            }
        }

        int getSize(int i) {
            return rank[findSet(i)];
        }
};

bool isValid(int a, int b, int row, int col) {
    return (a >= 0) && (a < row) && (b >= 0) && (b < col);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, a, b;
    cin >> q;

    string s;

    getline(cin, s);
    getline(cin, s);
    
    while(q--) {
    
        int row = 0;
        int col = 0;

        while(true) {
            getline(cin, s);
            if(isdigit(s[0])) break;
            strcpy(mat[row++], s.c_str());
            col = s.length();
        }

        UnionFind uf(row*col + 2*col);

        fori(i, row) {
            fori(j, col) {
                if(mat[i][j] == 'W') {
                    fori(k, 8) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if(isValid(tx, ty, row, col) && mat[tx][ty] == 'W') {
                            uf.join(i*col + j, tx*col + ty);
                        }
                    }
                }
            }
        }

        while(!s.empty()) {
            stringstream ss(s);
            ss >> a >> b;
            --a;
            --b;
            cout << uf.getSize(a*col + b) << endl;
            getline(cin, s);
        }
        
        if(q) cout << endl;
    }

    return 0;
}
