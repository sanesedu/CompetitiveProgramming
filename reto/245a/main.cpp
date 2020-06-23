
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

    long long t, prev, cur;

    bool f;
    bool b;

    while(cin >> t) {
        if(t == 0) break;
        
        cin >> prev;

        f = true;
        b = true;

        fori(i, t-1) {
            cin >> cur;
            if(cur <= prev) f = false;
            if(prev <= cur) b = false;
            prev = cur; 
        }
    
        if(f || b) cout << "DALTON\n";
        else cout << "DESCONOCIDOS\n";
    }

    return 0;
}
