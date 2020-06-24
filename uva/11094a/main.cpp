
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MAX 30

using namespace std;

int m, n, a, b;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N,M,X,Y;

char g[MAX][MAX], land;

int v[MAX][MAX];

int ans;

bool isValid(int i, int j) {
    return (i >= 0 && i < N && j >= 0 && j < M); 
}

int floodfill(int x, int y){
    
    int res;

    //wrap around
    if(y == M) y = 0; 
    else if(y == -1) y = M-1;

    if(!isValid(x, y)) return 0;

    if(v[x][y]) return 0;

    if(g[x][y] != land) return 0;

    v[x][y] = 1;
    
    res = 1;

    fori(i, 4) {
        res += floodfill(x + dx[i], y + dy[i]);
    }

    return res;
}

int main(){
    
    int i,j,t;
    
    while(scanf("%d %d", &N,&M) == 2) {
        //newline
        getchar();
        for(i = 0; i < N; ++i){
            for(j = 0; j < M; ++j){
                g[i][j] = getchar();
                v[i][j] = 0;
            }
            //newline
            getchar();
        }
        
        scanf("%d %d",&X,&Y);

        land = g[X][Y];
        
        floodfill(X,Y);
        
        ans = 0;
        
        for(i = 0; i < N; ++i){
            for(j = 0; j < M; ++j){
                if(g[i][j] == land){
                    t = floodfill(i,j);
                    ans = max(ans, t);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
