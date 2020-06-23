
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

void base6(int a) {
    
    if(a == 0) return;

    base6(a/6);

    cout << a % 6;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, a;
    cin >> n;

    while(n--) {
        cin >> a;
        if(a == 0) {
            cout << 0 << endl;
        } else {
            base6(a);
            cout << endl;
        }
    }

    return 0;
}
