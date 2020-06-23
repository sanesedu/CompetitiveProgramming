
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

    int n;
    cin >> n;

    int arr[n] = {};

    fori(i, n) cin >> arr[i];

    int m, x, y;
    cin >> m;

    fori(i, m) {
        cin >> x >> y;
        if(x - 2 >= 0) {
            arr[x-2] += (y-1);
        } 

        if(x <= n - 1) {
            arr[x] += (arr[x-1] - y);
        }

        arr[x-1] = 0;
    }

    fori(i, n) cout << arr[i] << endl;

    return 0;
}
