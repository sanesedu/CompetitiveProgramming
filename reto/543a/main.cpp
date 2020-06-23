
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool inside(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    
    return (pow(b.second.first - a.second.first, 2) + pow(b.second.second - a.second.second, 2)) < (pow(a.first + b.first, 2));

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, n, a, b, r;
    cin >> q;

    while(q--) {
        cin >> n;

        vector<pair<int, pair<int, int>>> arr;

        fori(i, n) {
            cin >> a >> b >> r;
            arr.pb(make_pair(r, make_pair(a, b)));
        }

        int res = 0;

        fori(i, n) {
            for(int j = i + 1; j < n; ++j) {
                if(inside(arr[i], arr[j])) ++res;
            }
        }
        cout << res << endl;
    }

    return 0;
}
