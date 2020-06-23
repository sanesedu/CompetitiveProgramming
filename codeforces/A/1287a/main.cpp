
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

    int t, n, res, cur;
    cin >> t;

    string s;

    bool b;

    while(t--) {
        cin >> n >> s;
        res = 0;
        cur = 0;
    
        b = false;

        fori(i, n) {
            if(b) {
                if(s[i] == 'A') {
                    res = max(res, cur);
                    cur = 0;
                } else {
                    ++cur;
                }
            } else if(s[i] == 'A') {
                b = true;
            }
        }

        cout << max(res, cur) << endl;
    }

    return 0;
}
