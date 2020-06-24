
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int price[25][25];

int memo[210][25];

int q, m, c, k;

int shop(int money, int g) {
    
    if(money < 0) return -1000000000; //fail
    
    if(g == c) return m - money; //all garments bought
    
    if(memo[money][g] != -1) {
        return memo[money][g];
    }

    int ans = -1;

    for(int model = 1; model <= price[g][0]; ++model) {
        ans = max(ans, shop(money - price[g][model], g + 1));
    }
    
    return memo[money][g] = ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    cin >> q;

    while(q--) {
        cin >> m >> c;
        fori(i, c) {
            cin >> price[i][0];
            fori(j, price[i][0]) {
                cin >> price[i][j+1];
            }
        }

        memset(memo, -1, sizeof(memo));
        int res = shop(m, 0);
        if(res < 0) cout << "no solution" << endl;
        else cout << res << endl;

    }

    return 0;
}
