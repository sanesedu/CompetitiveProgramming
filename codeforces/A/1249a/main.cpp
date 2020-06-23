
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
    
    int q, n;
    cin >> q;

    while(q--) {
        cin >> n;

        int arr[n] = {};

        fori(i, n) cin >> arr[i];

        sort(arr, arr+n);

        int res = 0;
        forb(i, 1, n-1) {
            if(arr[i] - arr[i-1] == 1) {
                ++res;
            }
        }

        if(res != 0) cout << 2 << endl;
        else cout << 1 << endl;
    }

    return 0;
}
