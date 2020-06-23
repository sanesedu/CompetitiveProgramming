
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<int> arr;

int ways(int i, int p, int n, int w) {
    
    if(p == 0) return 1;

    if(i == n) return 0;

    if(w < 0) return 0;

    if(arr[i] <= w) {
        return ways(i+1, p-1, n, w - arr[i]) + ways(i+1, p, n, w);
    } else {
        return ways(i+1, p, n, w);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, w, t;

    while(cin >> n >> w) {
        if(n == 0 && w == 0) break;
        arr.clear();

        fori(i, n) {
            cin >> t;
            arr.pb(t);
        }

        int res = ways(0, 2, n, w);

        cout << res << endl;
    }

    return 0;
}
