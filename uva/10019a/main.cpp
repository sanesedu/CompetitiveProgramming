
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int hextodec(int n) {
    
    int sum = 0;
    int pow = 1;

    while(n != 0) {
        sum += (n % 10) * pow;
        n /= 10;
        pow *= 16;
    }
    
    return sum;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int h, t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        
        bitset<32> b1(n);
        cout << b1.count() << " ";

        h = hextodec(n);
        bitset<32> b2(h);
        cout << b2.count() << endl;
    }

    return 0;
}
