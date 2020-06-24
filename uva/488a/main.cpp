
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

    int t, amp, f;
    cin >> t;

    while(t--) {
        cin >> amp >> f;

        while(f--) {
            for(int i = 1; i <= amp; ++i) {
                for(int j = 0; j < i; ++j) cout << i;
                cout << endl;
            }
            
            for(int i = amp-1; i >= 1; --i) {
                for(int j = 0; j < i; ++j) cout << i;
                cout << endl;
            }
            if(f) cout << endl;
        }
        if(t) cout << endl;
    }

    return 0;
}
