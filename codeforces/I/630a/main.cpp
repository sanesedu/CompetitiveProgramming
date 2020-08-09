
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

ll binpow(ll a, ll b) {
    ll res = 1;

    while(b > 0) {
        if(b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    ll n;
    cin >> n;

    ll res = 2 * 4 * 3 * binpow(4, n-3); //ways of placing the n cars at one end of the parking lot
    res += (n-3) * 4 * 3 * 3 * binpow(4, n-4); //ways of placing the n cars in the middle of the parking lot

    cout << res << endl;

    return 0;
}
