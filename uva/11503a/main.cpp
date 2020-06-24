
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

        void unionSet(int i, int j) {
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

        int getsize(int i) {
            return rank[findSet(i)];
        }

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, n, index;
    cin >> t;

    string a, b;

    while(t--) {
        
        cin >> n;

        map<string, int> names;
        index = 0;

        UnionFind uf(n * 2);

        fori(i, n) {
            cin >> a >> b;
            
            if(names.find(a) == names.end()) {
                names[a] = index++;
            }

            if(names.find(b) == names.end()) {
                names[b] = index++;
            }
            
            uf.unionSet(names[a], names[b]);
            
            cout << uf.getsize(names[a]) << endl;
        }

    }

    return 0;
}
