
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
    
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2) {
        
        x3 = x1 + abs(y2-y1);
        y3 = y1;

        x4 = x2 + abs(y2-y1);
        y4 = y2;

    } else if(y1 == y2) {
    
        x3 = x1;
        y3 = y1 + abs(x2-x1);

        x4 = x2;
        y4 = y2 + abs(x2-x1);

    } else if(abs(x2-x1) == abs(y2-y1)) {
        
        x3 = x1;
        y3 = y2;

        x4 = x2;
        y4 = y1;

    } else {
        cout << -1 << endl;
        return 0;
    }

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}
