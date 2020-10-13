
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
typedef pair<int, int> ii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, n, val;
    cin >> t;

    while(t--) {
        cin >> n;

        vector<int> count(10, 0);

        for(int i = 1; i <= n; ++i) {
            val = i;
            while(val > 0) {
                count[val % 10]++;
                val /= 10;
            }
        }

        fori(i, 10) {
            cout << count[i];
            if(i < 9) cout << " ";
        }

        cout << endl;
    }

    return 0;
}
