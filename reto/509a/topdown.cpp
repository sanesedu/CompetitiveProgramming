
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 0x3F3F3F3F

using namespace std;

int c,f;

long long arr[110][110];
long long memo[110][110];

int dx[] = {1, 0}; 
int dy[] = {0, 1};

long long solve(int x, int y) {
    
    if(y == c-1 && x == f-1) return 2;
    
    if(memo[x][y] != INF) return memo[x][y];
    
    long long res = INF;
    
    for(int i = 0; i < 2; ++i) {
        int a = x + dx[i];
        int b = y + dy[i];
        
        if(a >= 0 && a < f && b >= 0 && b < c) res = min(res, solve(a, b));
    }
    
    res -= arr[x][y];
    
    if(res < 2) res = 2;

//    cout << "pos: " << x << " " << y << ", " << res << endl;

    return (memo[x][y] = res);
}

void print() {
    fori(i, f) {
        fori(j, c) {
            cout << memo[i][j] << " ";
        } 
        cout << endl;
    }
}

int main() {

    while(cin >> c >> f) {
        fori(i, f) {
            fori(j, c) { 
                memo[i][j] = INF; 
                cin >> arr[i][j];
            }
        }
        
        cout << solve(0, 0) << endl;
 //       print();
    }
    
    return 0;
}
