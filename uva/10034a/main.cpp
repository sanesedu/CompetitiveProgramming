
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

double pos[100][2];

vector<pair<double, pair<int, int>>> edgeList;

class UnionFind {
    
    private: vector<int> rank, p;

    public: 

        int findSet(int i) {
            return (i == p[i]) ? i : (p[i] = findSet(p[i]));
        }
        
        int isSameSet(int i, int j) {
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
                    if(rank[x] == rank[y]) {
                        rank[y]++;
                    }
                }
            }
        }

        UnionFind(int n) {
            rank.assign(n, 0);
            p.assign(n, 0);

            fori(i, n) {
                p[i] = i;
            }
        }

};

double kruskal(int n) {
    
    sort(edgeList.begin(), edgeList.end());

    double cost = 0;

    UnionFind uf(n);

    for(int i = 0; i < (int) edgeList.size(); ++i) {
        pair<double, pair<int, int>> front = edgeList[i];
        if(!uf.isSameSet(front.second.first, front.second.second)) { //avoid cycle
            cost += front.first;
            uf.join(front.second.first, front.second.second);
        }
    }
    
    return cost;

}

int main() {

    int q, n;
    cin >> q;

    fori(j, q) {

        cin >> n;
        
        fori(i, n) {
            cin >> pos[i][0] >> pos[i][1];
        }

        edgeList.clear();
        
        fori(i, n) {
            forb(j, i+1, n-1) {
                double dist = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2));
                edgeList.pb(make_pair(dist, make_pair(i, j)));
            }
        }

        double res = kruskal(n);

        if(j) printf("\n");

        printf("%.2f\n", res);
    }

    return 0;
}
