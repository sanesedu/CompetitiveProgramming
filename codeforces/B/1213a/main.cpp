
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
    
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;

        vector<int> v(n);

        fori(i, n) cin >> v[i];

        int rmin = INT_MAX;
        int res = 0;

        forid(i, n) {
            if(v[i] > rmin) ++res;
            rmin = min(rmin, v[i]);
        }

        cout << res << endl;
    }

    return 0;
}
