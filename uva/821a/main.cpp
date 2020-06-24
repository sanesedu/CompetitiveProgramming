
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 110

using namespace std;

int adj[N][N];
bool used[N];

void floydWarshall() {
    
    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

}

int main() {

    int a, b, index;

    index = 1;

    while(cin >> a >> b) {
        
        if(a == 0 && b == 0) break;

        memset(adj, 63, sizeof(adj));
        memset(used, false, sizeof(used));

        while(true) {
            adj[a][b] = 1; 
            used[a] = true;
            used[b] = true;
            cin >> a >> b;
            if(a == 0 && b == 0) break;
        }
        
        floydWarshall();

        double sum, size;
        sum = 0;
        size = 0;
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(i != j) {
                    if(used[i] && used[j]) {
                        sum += adj[i][j];
                        ++size;
                    }
                }
            }
        }
        
        printf("Case %d: average length between pages = %.3f clicks\n", index++, sum/size);

    }

    return 0;
}
