
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

    int n, t;
    cin >> n;

    vector<pair<int, int>> arr(n);

    fori(i, n) {
        cin >> t;
        arr[i] = make_pair(t, i);
    }

    sort(all(arr));

    int res = 0;

    forid(i, n) {
        res += (arr[i].first * ((n-1) - i) + 1);  
    }

    cout << res << endl;

    forid(i, n) {
        cout << arr[i].second + 1 << " ";
    }

    cout << endl;

    return 0;
}
