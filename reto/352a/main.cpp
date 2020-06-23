
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
    
    private: vector<int> p, rank;
    public:
        
        UnionFind(int n) {
            rank.assign(n, 1); //height of each tree
            p.assign(n, 0); 
            
            for(int i = 0; i < n; ++i) { //initialize each element to its own tree
                p[i] = i;
            }
        }

        int findSet(int i) {
            //if representative of tree is itself return element, else, look for representative
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if(!isSameSet(i, j)) {
                int x = findSet(i);
                int y = findSet(j);
                if(rank[x] > rank[y]) { //join smaller tree to larger one
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
            a--;
            b--;
            uf.unionSet(a, b);
        }

        int res = 0;

        fori(i, n) {
            res = max(res, uf.getSize(i));
        }

        cout << res << endl;
    }
    
    return 0;
}
