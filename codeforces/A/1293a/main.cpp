
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

    int a, i, t, n, s, k;
    cin >> t;

    while(t--) {
        
        cin >> n >> s >> k;

        vector<int> arr;
        --s;

        fori(j, k) {
            cin >> a;
            --a;
            arr.pb(a);
        }
        
        for(i = 0; i < n; ++i) {
            if(s + i < n && find(all(arr), s + i) == arr.end()) break;
            if(s - i >= 0 && find(all(arr), s - i) == arr.end()) break;
        }

        cout << i << endl;
    }

    return 0;
}
