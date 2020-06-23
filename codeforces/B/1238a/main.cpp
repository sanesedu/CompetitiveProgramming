
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

    int q, n, r, t;
    cin >> q;

    while(q--) {

        cin >> n >> r;

        int arr[n] = {};

        fori(i, n) cin >> arr[i];
        
        sort(arr, arr + n);

        n = unique(arr, arr+n) - arr;

        int res = 0;
        
        forid(i, n) {
            res += (arr[i] - (res * r) > 0); //add necessary shots if position after res shots is > 0
        }

        cout << res << endl;
    }

    return 0;
}
