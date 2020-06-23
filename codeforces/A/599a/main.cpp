
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
    
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    int res = 0;
    int pos = 0;

    if(d1 < d2) {
        pos = 2;
        res += d1;
    } else {
        pos = 1;
        res += d2;
    }

    if(d3 < d1 + d2) {
        res += d3;
    } else {
        res += (d1 + d2);
    }

    if(pos == 1) {
        if(d1 < d2 + d3) {
            res += d1;
        } else {
            res += (d2 + d3);
        }
    } else {
        if(d2 < d1 + d3) {
            res += d2;
        } else {
            res += (d1 + d3);
        }
    }

    cout << res << endl;

    return 0;
}
