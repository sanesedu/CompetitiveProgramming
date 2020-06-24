
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forid(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(long long i = (long long)(a); i <= (long long)(b); ++i)

using namespace std;

int tc, n, people;

int price[1010];
int weight[1010];

int dp[1010][35];

int solve(int id, int w) {
    
    if (id >= n || w == 0) return 0;
    
    if (dp[id][w] != -1) return dp[id][w];
    
    if (weight[id] > w) {
        return dp[id][w] = solve(id + 1, w);
    } else {
        return dp[id][w] = max(solve(id + 1, w), price[id] + solve(id + 1, w - weight[id]));
    }
}
 
int main() {
    
    scanf("%d", &tc);
    
    while (tc--) {
    
        memset(dp, -1, sizeof(dp));
    
        scanf("%d", &n);
    
        fori(i, n) { 
            scanf("%d %d", &price[i], &weight[i]);
        }

        scanf("%d", &people);
    
        int ans = 0;
        int mw;
    
        while (people--) {
            scanf("%d", &mw);
            ans += solve(0, mw);
        }
    
        printf("%d\n", ans);
    }

    return 0;
}
