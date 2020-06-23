
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define forbe(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, k;
    cin >> n >> k;

    int arr[n] = {};

    int mx, mn;
    mx = 0;
    mn = (int) 1e5;

    fori(i, n) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }

    if(mx - mn > k) cout << "NO\n";
    else {
        cout << "YES\n";
        fori(i, n) {
            fori(j, mn) { //all piles have mn or mn+1 of color 1 -> diff <= 1
                if(j) cout << " ";
                cout << "1";
            }
            forbe(j, mn, arr[i]) { //one of each color -> diff for color <= 1
                if(j) cout << " ";
                cout << j - mn + 1;
            }
            cout << "\n";
        }
    }

    return 0;
}
