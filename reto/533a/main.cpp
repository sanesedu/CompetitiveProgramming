
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

    int q, n, t, prev;
    cin >> q;

    while(q--) {
        cin >> n;

        n *= 8;

        vector<int> arr;
    
        prev  = 0;

        while(1) {
            cin >> t;
            if(t == 0) break;
            prev += t;
            arr.pb(prev);
        }

        vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), n);

        if(it == arr.end()) cout << "SIGAMOS RECICLANDO\n";
        else cout << (it - arr.begin() + 1) << endl;
    }

    return 0;
}
