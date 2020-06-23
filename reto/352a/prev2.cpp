
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

class UnionFind {

    public:
        vector<int> p, rank;
        
        UnionFind(int n) {
            rank.assign(n, 0);
            p.assign(n, 0);
            fori(i, n) {
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (i == p[i]) ? i : (p[i] = findSet(i));
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
                } else {
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }

        int getSize(int i) {
            cout << rank[findSet(i)] << endl;
            return rank[findSet(i)];
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, n, m, a, b;
    cin >> q;

    while(q--) {
        cin >> n >> m;

        UnionFind uf(n);

        fori(i, m) {
            cin >> a >> b;
            uf.join(a-1, b-1);
        }

        int res = 0;

        fori(i, n) {
            cout << res << endl;
            res = max(res, uf.rank[uf.p[i]]);
        }

        cout << res << endl;
    }

    return 0;
}
