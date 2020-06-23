
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

    int c, r;

    int cols, rows, frigs;

    while(cin >> cols >> rows >> frigs) {
        
        if(cols == 0 && rows == 0 && frigs == 0) break;

        vector<int> x(frigs);
        vector<int> y(frigs);

        fori(i, frigs) {
            cin >> x[i] >> y[i];
        }
        
        sort(all(x));
        sort(all(y));
        
        cout << x[(ceil((double)frigs/2)-1)] << " " << y[(ceil((double)frigs/2)-1)] << endl;
    }

    return 0;
}
