
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

    int v[n] = {};

    fori(i, n) cin >> v[i];

    sort(v, v + n);

    int res = n-2;

    for(int i = 1; i < n && v[i] == v[0]; ++i) --res;
    
    for(int i = n - 2; i >= 0 && v[i] == v[n-1]; --i) --res;

    cout << max(0, res) << endl;

    return 0;
}
