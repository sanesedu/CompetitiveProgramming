
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool isPowerOfFour(long long n) {
    return (n != 0 && ((n&(n-1)) == 0) && !(n & 0xAAAAAAAA));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    string s;
    cin >> s;

    bitset<128> b(s);

    long long temp = b.to_ulong();

    long long orig = temp;

    long long powers = 0;

    while(temp >= 1) {
       if(isPowerOfFour(temp) && temp != orig) {
           ++powers;
       }
       --temp;
    }

    cout << powers << endl;

    return 0;
}
