
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    long long n, m, t, l, r;
    cin >> n;

    long long v[n+1] = {};

    v[0] = 0;
    forb(i, 1, n) cin >> v[i];

    long long u[n+1] = {};

    copy(v, v + (n+1), u);

    sort(u, u + (n+1));

    long long res[n+1], res2[n+1];

    res[0] = v[0];
    res2[0] = u[0];

    forb(i, 1, n) res[i] = res[i-1] + v[i];
    forb(i, 1, n) res2[i] = res2[i-1] + u[i];
   
    cin >> m;

    while(m--) {
        cin >> t >> l >> r;

        if(t == 1) {
            cout << res[r] - res[l-1] << endl;
        } else {
            cout << res2[r] - res2[l-1] << endl;
        }
    }

    return 0;
}
