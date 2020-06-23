
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, res;

    while(cin >> n) {
        
        if(n == 0) break;

        vector<pair<int, int>> arr(n);

        fori(i, n) cin >> arr[i].first >> arr[i].second;
        
        sort(all(arr));

        res = arr[0].second - arr[0].first + 1;

        for(int i = 1; i < n; ++i) {
            res += (arr[i].second - arr[i].first + 1);
            if(arr[i].first <= arr[i-1].second) {
                res -= (arr[i-1].second - arr[i].first + 1);
            }
        }
        
        cout << res << endl;
    }

    return 0;
}
