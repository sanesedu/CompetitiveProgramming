
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 7500
#define INF 100000000

using namespace std;

int coins[] = {50, 25, 10, 5, 1};

int dp[N];

int ways(int type, int val) {
    
    if(val == 0) return 1;
    
    if(val < 0) return 0;
   
    if(type == 5) return 0;

    if(dp[val] != -1) return dp[val];

    return dp[val] = ways(type + 1, val) + ways(type, val - coins[type]);
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;

    while(cin >> n) {
        memset(dp, -1, sizeof(dp));
        cout << ways(0, n) << endl;
    }

    return 0;
}
