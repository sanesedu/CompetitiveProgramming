
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
    
    int t;
    cin >> t;

    int b, p, f, h, c;

    fori(i, t) {
        cin >> b >> p >> f >> h >> c;

        int profit = 0;

        if(h < c) {
            swap(h, c);
            swap(p, f);
        }

        int bl = min(b/2, p);
        int ml = min((b - 2*bl) / 2, f);
        profit = bl * h + ml * c;

        cout << profit << endl;

    }

    return 0;
}
