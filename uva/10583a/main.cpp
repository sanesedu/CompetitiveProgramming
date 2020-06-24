
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
   
    private:
        vector<int> p, rank;
        int rel;

    public:
        UnionFind(int n) {
            rel = n;
            p.assign(n, 0);
            rank.assign(n, 0);
            fori(i, n) p[i] = i;
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
                } else {
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
                --rel;
            }
        }

        int getRel() {
            return rel;
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, m, a, b;

    int index = 1;

    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
   
        UnionFind uf(n);
    
        fori(i, m) {
            cin >> a >> b;
            --a;
            --b;
            uf.join(a, b);
        }

        cout << "Case " << index++ << ": " << uf.getRel() << endl;
    }

    return 0;
}
