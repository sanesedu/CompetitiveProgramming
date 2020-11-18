
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
    
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;

        /* 
        we are considering values 4n, 4n-2, 4n-4,...,2n+2
            - as they are all even, gcd(a,b)=2!=1 for every a,b, so the first condition is never fulfilled
            - the first divisor of 4n will be 2n, which we are not considering, so the second condition is also never fulfilled
        */
        fori(i, n) {
            cout << 4*n - 2*i << " ";
        }
        cout << endl;
    }

    return 0;
}
