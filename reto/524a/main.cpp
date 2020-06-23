
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.first - a.second) < (b.first - b.second);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int res, n, c, t;

    while(cin >> n) {
        if(n == 0) break;
    
        cin >> c >> t;

        vector<pair<int, int>> arr(n);

        fori(i, n) cin >> arr[i].first;
        fori(i, n) cin >> arr[i].second;

        sort(all(arr), cmp);

        res = 0;

        for(int i = 0; i < c; ++i) {
            res += arr[i].first;
        }

        for(int i = n-1; i >= n - t; --i) {
            res += arr[i].second;
        }

        for(int i = c; i < n-t; ++i) {
            res += min(arr[i].first, arr[i].second);
        }

        cout << res << endl;
    }

    return 0;
}
