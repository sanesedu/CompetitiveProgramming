
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

    int b, n, d, c, v;

    bool ok;

    while(cin >> b >> n) {

        if(b == 0 && n == 0) break;

        vector<int> arr(b);

        fori(i, b) cin >> arr[i];

        fori(i, n) {
            cin >> d >> c >> v;
            --d;
            --c;
            arr[d] -= v;
            arr[c] += v;
        }
        
        ok = true;

        for(int i = 0; i < b && ok; ++i) {
            if(arr[i] < 0) ok = false;
        }

        if(ok)  cout << "S\n";
        else cout << "N\n";

    }

    return 0;
}
