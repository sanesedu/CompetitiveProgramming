
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

    int cases;
    cin >> cases;

    ll n, t, m, d, i, res, count;

    while(cases--) {
        cin >> n >> t >> m >> d >> i;
    
        res = 0;
        count = 0;

        while(n > 0) {
            if(n <= m) {
                res += (t*n); //tiempo hacer largos restantes 
                n = 0;
            } else {
                res += (t*m); //tiempo hacer largos
                res += (d + count * i); //tiempo descanso 
                n -= m;
            }
            ++count;
        }

        cout << res << endl;
    }

    return 0;
}
