
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
    
    int t, n, d, a, b;
    cin >> t;

    fori(i, t) {
        
        cin >> n;
        
        a = 0;
        b = 0;;
        
        fori(j, n) {
            cin >> d;
            ++d;
            a += ceil((double)d/30.0) * 10;
            b += ceil((double)d/60.0) * 15;
        }
        
        cout << "Case " << i+1 << ": ";

        if(a < b) {
            cout << "Mile " << a << endl;
        } else if(a > b) {
            cout << "Juice " << b << endl;
        } else {
            cout << "Mile Juice " << a << endl; 
        }
    }

    return 0;
}
