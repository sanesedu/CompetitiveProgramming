
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

long long trailing(ll a, ll b) {
    ll res = 1;
    ll mod = 1000;

    while(b > 0) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

/*
    we are trying to approximate the answer by solving: a^b = 10^c
    the integer part of c indicates the number of digits of the solution
    if we only consider the fractional part, 10^c will give us the first few digits of the solution
*/
long long leading(ll a, ll b) {
    
    double c = b * log10(a);
    c -= floor(c); //we remove the integer part 
    
    double lead = pow(10, c) * 100; //we multiply by 100 to obtain the first 3 digits
    
    return (int)lead;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t;
    ll a, b;

    cin >> t;

    while(t--) {
        cin >> a >> b;
        printf("%d...%03d\n", leading(a, b), trailing(a, b));
    }

    return 0;
}
