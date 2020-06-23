
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

int nge(vector<int> arr, int val, int pos, int n) {
    
    for(int i = pos+1; i < n; ++i) {
        if(arr[i] > val) {
            return i;
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, t, val;

    ll res;

    while(cin >> n) {
        if(n == 0) break;

        vector<int> arr(n);

        fori(i, n) {
            cin >> arr[i];
        }
        
        res = 0;

        for(int i = 0; i < n; ++i) {
        
            if(arr[i] == n) {
                res += (n - i);
                continue;
            }    

            val = nge(arr, arr[i], i, n);

            if(val == -1) {
                res += (n - i);
            } else {
                res += (val - i);
            }
        }

        cout << res << endl;
    }

    return 0;
}
