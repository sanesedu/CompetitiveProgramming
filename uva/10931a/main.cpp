
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int decbin(int n) {
    
    if(n == 0) return 0;

    int t = n % 2;

    int res = decbin(n/2);

    cout << t;

    return res + t;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;

    while(cin >> n) {
        if(n == 0) break;

        cout << "The parity of ";

        int bin = decbin(n);

        cout << " is " << bin << " (mod 2)." << endl;
    }

    return 0;
}
