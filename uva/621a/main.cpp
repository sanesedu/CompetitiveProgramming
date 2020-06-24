
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

    int t, len;
    cin >> t;

    string s;

    while(t--) {
        cin >> s;
        
        len = s.length();

        if(s == "1" || s == "4" || s == "78") {
            cout << "+" << endl;
        } else if(s[len-2] == '3' && s[len-1] == '5') {
            cout << "-" << endl;
        } else if(s[0] == '9' && s[len-1] == '4') {
            cout << "*" << endl;
        } else {
            cout << "?" << endl;
        }
    }

    return 0;
}
