
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

    int a, res, t, n, s, k;
    cin >> t;

    while(t--) {
        
        cin >> n >> s >> k;

        vector<bool> arr(n, true);
        --s;

        fori(i, k) {
            cin >> a;
            --a;
            arr[a] = false;
        }
        
        res = 0;

        for(int i = 0; i < n; ++i) {
            if(s + i < n && arr[s+i]) break;
            if(s - i >= 0 && arr[s-i]) break;
            ++res;
        }

        cout << res << endl;
    }

    return 0;
}
