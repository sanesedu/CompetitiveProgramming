
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

    int l, r, n, m, p, a, b;

    while(cin >> n) {
        
        vector<int> arr(n);

        fori(i, n) cin >> arr[i];

        cin >> m;

        sort(all(arr));

        a = -1;
        b = -1;

        l = 0;
        r = n-1;

        while(l < r) {
            if(arr[l] + arr[r] == m) {
                a = arr[l];
                b = arr[r];
                ++l;
                --r;
            } else if(arr[l] + arr[r] < m) {
                ++l;
            } else {
                --r;
            }
        }

        cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl;
        cout << endl;
    }

    return 0;
}
