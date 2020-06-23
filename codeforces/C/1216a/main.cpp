
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool ok(int a, int b, int a1, int b1, int a2, int b2) {
    return (a < a1 || b < b1 || a > a2 || b > b2);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    
    x1 *= 2; x2 *= 2; x3 *= 2; x4 *= 2; x5 *= 2; x6 *= 2;    
    y1 *= 2; y2 *= 2; y3 *= 2; y4 *= 2; y5 *= 2; y6 *= 2;    

    for(int i = x1; i <= x2; ++i) {
        if(ok(i, y1, x3, y3, x4, y4) && ok(i, y1, x5, y5, x6, y6)) {
            cout << "YES\n";
            return 0; 
        }
        if(ok(i, y2, x3, y3, x4, y4) && ok(i, y2, x5, y5, x6, y6)) {
            cout << "YES\n";
            return 0; 
        }
    } 

    for(int i = y1; i <= y2; ++i) {
        if(ok(x1, i, x3, y3, x4, y4) && ok(x1, i, x5, y5, x6, y6)) {
            cout << "YES\n";
            return 0; 
        }
        if(ok(x2, i, x3, y3, x4, y4) && ok(x2, i, x5, y5, x6, y6)) {
            cout << "YES\n";
            return 0; 
        }
    }

    cout << "NO\n"; 
    
    return 0;
}
