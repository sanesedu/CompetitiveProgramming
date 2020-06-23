
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

        fori(i, n) cin >> arr[i].second >> arr[i].first;
        
        sort(all(arr));

        res = arr[0].first - arr[0].second + 1;

        for(int i = 1; i < n; ++i) {
            if(arr[i-1].first < arr[i].second) {
                res += (arr[i].first - arr[i].second + 1); 
            } else {
                res += (arr[i].first - arr[i-1].first);
                
                if(arr[i].second < arr[i].first
            }
        }
        
        cout << res << endl;
    }

    return 0;
}
