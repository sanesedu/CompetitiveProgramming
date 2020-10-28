
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 2020

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int arr[N], lis[N], lds[N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, n, res;
    cin >> t;

    while(t--) {
        cin >> n;

        fori(i, n) cin >> arr[i];
        
        // compute number of elements larger than arr[i] that come after i (counting itself)
        // these elements can be added at the end of the train array 
        forid(i, n) {
            lis[i] = 1;
            for(int j = i + 1; j < n; ++j) {
                if(arr[j] > arr[i]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        
        // compute number of elements smaller than arr[i] that come after i (counting itself)
        // these elements can be added at the beginning of the train array 
        forid(i, n) {
            lds[i] = 1;
            for(int j = i + 1; j < n; ++j) {
                if(arr[j] < arr[i]) {
                    lds[i] = max(lds[i], 1 + lds[j]);
                }
            }
        }

        res = 0;

        fori(i, n) {
            res = max(res, lis[i] + lds[i] - 1); // -1 to avoid double counting the element
        }

        cout << res << endl;
    
    }

    return 0;
}
