
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

    int res, n, l, r;

    bool turn;

    while(cin >> n) {
        
        if(n == 0) break;

        res = 0;

        l = 0;
        r = n - 1;

        turn = true;

        while(true) {
            
            if(turn) {
                if(l == 0 || r - l > 1) ++res;
                else  break;
                turn = false;
                if(l > 0) r -= 2;
            } else {
                if(r - l > 1) ++res;
                else break;
                turn = true;
                l += 2;
            }
        }
        
        cout << res << endl;
    }

    return 0;
}
