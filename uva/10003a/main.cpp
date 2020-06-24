
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(int i = 0; i < (int)(n); ++i)
#define forld(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 4000000

using namespace std;

int memo[60][60];

vector<int> arr;

int solve(int l, int r) {
    
    if(r - l == 1) return 0;

    if(memo[l][r] != -1) return memo[l][r];

    int res = INF;

    for(int i = l + 1; i < r; ++i) {
        res = min(res, solve(l, i) + solve(i, r) + (arr[r] - arr[l])); 
    }

    return (memo[l][r] = res);
}

int main() {

    int l, n, c;

    while(scanf("%d", &l)) {
        if(l == 0) break;

        scanf("%d", &n);

        arr.clear();

        arr.pb(0);

        fori(i, n) {
            cin >> c;
            arr.pb(c);
        }
            
        arr.pb(l);

        memset(memo, -1, sizeof(memo));

        int res = solve(0, n+1);
    
        printf("The minimum cutting is %d.\n", res);
    }

    return 0;
}
