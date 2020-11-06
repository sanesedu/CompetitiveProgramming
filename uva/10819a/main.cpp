
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 120
#define M 10020

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int m, n;

int cost[N], value[N];

int memo[N][M];

int solve(int index, int c) {
    // impossible to apply discount
    if(c > m && m < 1800) return -1000;
    
    // applying discount is not enough
    if(c > m + 200) return -1000;
    
    if(index == n) {
        if(c > m && c <= 2000) return -1000;
        else return 0;
    }

    if(memo[index][c] != -1) return memo[index][c];

    int res = max(solve(index+1, c), value[index] + solve(index+1, c+cost[index]));

    return memo[index][c] = res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    while(cin >> m >> n) {
        fori(i, n) cin >> cost[i] >> value[i];        
        
        memset(memo, -1, sizeof(memo));
       
        cout << solve(0, 0) << endl;
    }

    return 0;
}
