
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
            rank.assign(n, 0);
            p.assign(n, 0);
            fori(i, n) {
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
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
                    if(rank[x] == rank[y]) rank[y]++;
                }       
            }
        }

};

int main() {

    int q, n, a, b;

    char c;

    string s;

    scanf("%d", &q);

    fori(i, q) {

        if(i != 0) cout << endl;

        scanf("\n%d\n", &n);
        UnionFind uf(n);
        
        int suc = 0;
        int unsuc = 0;

        while(1) {
            if(!getline(cin, s) || s.empty()) break;
            sscanf(s.c_str(), "%c %d %d", &c, &a, &b);
            if(c == 'c') {
                uf.unionSet(a-1, b-1);
            } else {
                bool res = uf.isSameSet(a-1, b-1);
                if(res) ++suc;
                else ++unsuc;
            }
        }

        cout << suc << "," << unsuc << endl;
    }

    return 0;
}
