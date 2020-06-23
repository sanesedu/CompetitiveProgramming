
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    return (min(a.first * 2, a.second) - a.first) > (min(b.first * 2, b.second) - b.first);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n, f;
    cin >> n >> f;

    long long a, b;
    vector<pair<long long, long long>> v(n);

    fori(i, n) {
        cin >> a >> b;
        v[i].first = a, v[i].second = b;
    }

    sort(v.begin(), v.end(), cmp);

    long long res = 0;

    fori(i, n) {
        if(i < f) {
            res += min(2*v[i].first, v[i].second);
        } else {
            res += min(v[i].first, v[i].second);
        }
    }

    cout << res << endl;

    return 0;
}
