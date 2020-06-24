
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

    int d, r, t, a, b, c, e;

    while(cin >> d >> r >> t) {

        int a = 0, b = 0, c = 0, e = 0;

        while(true) {
            ++a;
            
            if(a >= 4) { //rita starts accumulating candles at 4
                c += a;
            }

            if(a - b > d) { //we need to increase b to maintain difference d
                ++b;
                if(b >= 3) { //theo starts accumulating candles at 3
                    e += b;
                }
            }
            
            if(c + e == r + t) { //same amount of candles as original
                break;
            }
        }

        cout << r - c << endl;

    }

    return 0;
}
