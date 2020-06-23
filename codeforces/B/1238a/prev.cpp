
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

    int q, n, r, t;
    cin >> q;

    while(q--) {
        cin >> n >> r;

        set<int> arr;

        fori(i, n) {
            cin >> t;
            arr.insert(t);
        }

        int res = 0;
        
        while(arr.size() > 0) {
 
            arr.erase(remove(arr.begin(), arr.end(), arr.end()-1), arr.end());

            fori(i, arr.size()) {
                if(arr[i] <= r) arr[i] = -1;
                else arr[i] -= r;
            }

            arr.erase(remove(arr.begin(), arr.end(), -1), arr.end());

            ++res;
        }

        cout << res << endl;
    }

    return 0;
}
