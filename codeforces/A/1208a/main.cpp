
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
    
    int t, a, b, n;
    cin >> t;

    fori(i, t) {
        cin >> a >> b >> n;

        switch(n % 3) {
            case 0:
                cout << a << endl;
                break;
            case 1:
                cout << b << endl;
                break;
            case 2:
                cout << (a ^ b) << endl;
                break;
        }
    }

    return 0;
}
