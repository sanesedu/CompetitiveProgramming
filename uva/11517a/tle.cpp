
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, total, n, pay, num;

void solve(vector<int> coins, int p, int used) {

    if(p >= total) {
        if(p < pay) {
            pay = p;
            num = used;
            return;
        } else if(p == pay) {
            if(used < num) {
                num = used;
            }
            return;
        }
    }

    fori(i, coins.size()) {
        if(p + coins[i] <= pay) solve(coins, p + coins[i], used+1);
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    cin >> t;

    while(t--) {
        cin >> total;
        cin >> n;

        vector<int> coins(n);

        fori(i, n) cin >> coins[i];
        
        pay = INT_MAX;
        num = INT_MAX;
        
        solve(coins, 0, 0);

        cout << pay << " " << num << endl;
    }

    return 0;
}
