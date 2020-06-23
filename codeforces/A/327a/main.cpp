
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
    
    int n;
    cin >> n;

    int a[n] = {};
    int b[n] = {};

    fori(i, n) cin >> a[i];

    int res = 0;

    fori(i, n) {
        forb(j, 0, i) {
            
            for(int k = 0; k < j; ++k) { //copy values before flip interval
                b[k] = a[k];
            }

            for(int k = j; k <= i; ++k) { //flip interval values
                b[k] = 1 - a[k];
            }

            for(int k = i+1; k < n; ++k) { //copy values after interval
                b[k] = a[k];
            }

            int ones = 0;

            fori(k, n) if(b[k] == 1) ++ones;
            
            res = max(res, ones);

        }
    }

    cout << res << endl;

    return 0;
}
