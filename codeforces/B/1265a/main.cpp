
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

    int x, l, r, t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        
        vector<int> pos(n);

        fori(i, n) {
            cin >> x;
            --x;
            pos[x] = i;
        }

        l = n;
        r = 0;

        fori(i, n) {
            l = min(l, pos[i]);
            r = max(r, pos[i]);

            if(r - l == i) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }

    return 0;
}
