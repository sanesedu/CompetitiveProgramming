
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

    char tmp;
    int t, n, a, b, h, ca, cb, res;
    cin >> t;

    while(t--) {
        cin >> n >> a >> b >> h;
        ca = cb = 0;
        
        fori(i, n) {
            cin >> tmp;
            if(tmp == '1') cb++;
            else ca++;
        }
    
        if(a + h < b) {
            b = a + h;
        } else if(b + h < a) {
            a = b + h;
        }

        res = a * ca + b * cb;

        cout << res << endl;
    }

    return 0;
}
