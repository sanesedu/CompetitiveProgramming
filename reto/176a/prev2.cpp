
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int dx[] = {1,-1,0,0,1,-1,-1,1};
int dy[] = {0,0,1,-1,1,-1,1,-1};

char arr[1001][1001];

int r, c, res;

void dfs(int a, int b){
    
    int cnt = 0;
    fori(i, 8) {
        int x = a + dx[i];
        int y = b + dy[i];
        if(x >= 0 && x < r && y >= 0 && y < c && arr[x][y] == '*') cnt++;
    }
    if(cnt >= 6) res++;
}

int main() {
    while(scanf("%d%d",&c,&r) == 2) {
        if(c == 0 && r == 0) break;

        fori(i, r) {
            fori(j, c) {
                cin >> arr[i][j];
            }
        }

        res = 0;
        
        fori(i, r) {
            fori(j, c) {
              if(arr[i][j]=='-') dfs(i,j);
            }
        }

        cout << res << '\n';
    }
    return 0;
}
