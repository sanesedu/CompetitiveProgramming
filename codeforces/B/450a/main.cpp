
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

    const long long MOD = 1000000007;

    long long x, y, n, z;
    cin >> x >> y >> n;

    long long arr[6] = {};
    
    if(x == 0 && y == 0) {
        cout << 0 << endl;
        return 0;
    } else if(x == 0) {
        arr[0] = 0;
        arr[1] = (y + MOD) % MOD;
        arr[2] = arr[1];
        arr[3] = 0;
        arr[4] = (-y + MOD) % MOD;
        arr[5] = arr[4]; 

    } else if(y == 0) {
        arr[0] = (x + MOD) % MOD;
        arr[1] = 0;
        arr[2] = (-x + MOD) % MOD;
        arr[3] = arr[2];
        arr[4] = 0; 
        arr[5] = arr[0]; 
        
    } else {
        arr[0] = (x + MOD) % MOD;
        arr[1] = (y + MOD) % MOD;
        arr[2] = (arr[1] - arr[0] + MOD) % MOD;
        arr[3] = (-x + MOD) % MOD;
        arr[4] = (-y + MOD) % MOD; 
        arr[5] = (arr[4] - arr[3] + MOD) % MOD; 
    }

    cout << arr[(n-1) % 6] << endl;

    /* cout << x << " " << y << " ";    
    while(n < 50) {
        z = ((y - x) + MOD) % MOD;
        x = y;
        y = z;
        cout << z << " ";
        ++n;
    }

    cout << endl; */

    return 0;
}
