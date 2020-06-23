
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

    int mx, t, r, g, b;
    cin >> t;

    bool f;

    while(t--) {
        cin >> r >> g >> b;
        
        mx = max(r, max(g, b));
        
        f = false;

        if(mx == r) {
            if(r <= g + b + 1) f = true;
        } else if(mx == g) {
            if(g <= r + b + 1) f = true;
        } else {
            if(b <= r + g + 1) f = true;
        }
    
        if(f) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
