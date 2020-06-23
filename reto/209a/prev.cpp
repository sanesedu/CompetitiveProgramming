
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

    string s;
    int t, n, l, r, tmp, len;

    while(getline(cin, s)) {
        
        vector<int> arr;
    
        arr.pb(0);

        len = s.length();

        fori(i, len) {
            if(s[i] == 'T') arr.pb(i); 
        }

        arr.pb(len - 1);
       
        vector<int>::iterator low;

        cin >> t;

        while(t--) {
            cin >> n;
            --n;
            low = lower_bound(all(arr), n);
            
            if(*low == n) {
                cout << "AQUI\n";
            } else {
                r = *low - n;
                --low;
                l = n - *low;
               
                if(l < r) cout << "PENINSULA\n";
                else if(r < l) cout << "ISLAS\n";
                else {
                    //tmp = (n - l) - (len - 1 - (r + n));
                    tmp = len - n;
                    if(n <= tmp) cout << "PENINSULA\n"; 
                    else cout << "ISLAS\n";
                }
            } 
        } 
        cin.ignore();
    }

    return 0;
}
