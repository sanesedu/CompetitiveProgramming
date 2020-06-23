
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
    int ctotal = 0;
    int mtotal = 0;

    fori(i, 3) {
        cin >> t;
        ctotal += t;
    }
    
    fori(i, 3) {
        cin >> t;
        mtotal += t;
    }

    cin >> n;

    int needed = (ctotal / 5);
    if(ctotal % 5 != 0) ++needed;
    needed += (mtotal / 10);
    if(mtotal % 10 != 0) ++needed;

    if(needed <= n) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
