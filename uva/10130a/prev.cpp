
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forid(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(long long i = (long long)(a); i <= (long long)(b); ++i)

using namespace std;

long long t, n, p, w, g, h;

long long memo[1010][40];

long long kps(vector<pair<long long, long long>> arr, long long kind, long long weight) {

    if(weight == 0) return 0;

    if(kind >= n) return 0;

    if(memo[kind][weight] != -1) return memo[kind][weight];

    long long res = 0;

    if(arr[kind].second > weight) {
        res = kps(arr, kind + 1, weight);
    } else {
        res = max(kps(arr, kind + 1, weight), arr[kind].first + kps(arr, kind+1, weight - arr[kind].second)); 
    }

    return (memo[kind][weight] = res);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    cin >> t;

    while(t--) {
        cin >> n;
        
        vector<pair<long long, long long>> arr(n);
        
        fori(i, n) {
            cin >> p >> w;
            arr[i].first = p;
            arr[i].second = w;
        }

        memset(memo, -1, sizeof(memo));

        cin >> g;

        long long res = 0;
        
        while(g--) {
            cin >> h;
            res += kps(arr, 0, h);;
        }
       
        cout << res << endl;

    }

    return 0;
}
