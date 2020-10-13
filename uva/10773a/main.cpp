
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

    int t;
    double d, v, u;
    cin >> t;

    fori(i, t) {
        
        cin >> d >> v >> u;

        cout << "Case " << i+1 << ": ";
        
        if(v == 0 || u == 0 || v >= u) {
            cout << "can't determine" << endl;
        } else {
            double t1 = d / u; //shortest time
            double t2 = d / sqrt(u*u - v*v);
            
            printf("%.3f\n", abs(t1 - t2));
        }
        
    }

    return 0;
}
