
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

    ll n, t, m, d, i, res, count, tmp;

    while(cases--) {
        cin >> n >> t >> m >> d >> i;

        res = (n/m) * (m*t) + (n%m)*t; //tiempo largos
        
        if(n % m == 0) { //todas las series completas
            res += (n/m - 1) * d; //tiempo descanso
            tmp = (n/m - 2) * (n/m - 1) / 2; //tiempo extra
        } else {
            res += (n/m) * d; //tiempo descanso
            tmp = (n/m) * (n/m - 1) / 2; //tiempo extra
        }

        res += (i * tmp);

        cout << res << endl;
    }

    return 0;
}
