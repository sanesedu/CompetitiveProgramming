
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<int> arr;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, w, t;

    while(cin >> n >> w) {
        if(n == 0 && w == 0) break;
        arr.clear();

        fori(i, n) {
            cin >> t;
            arr.pb(t);
        }

        long long res = 0;

        long long val, pos;

        sort(all(arr));

        fori(i, n) {
            val = (w - arr[i]+1);
            pos = (lower_bound(all(arr), val) - (arr.begin()+i)) -1;
            if(pos >= 0) res += pos;
        }

        cout << res << endl;
    }

    return 0;
}
