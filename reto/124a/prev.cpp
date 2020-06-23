
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

    string a, b;

    bool end = true;

    while(end) {

        cin >> a >> b;

        if(a == "0"  && b == "0") {
            end = false;
            break;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string m, n; //m=shorter, n=longer

        if(a.length() <= b.length()) {
            m = a;
            n = b;
        } else {
            m = b;
            n = a;
        }

        int carry = 0, p, t, res = 0, i;

        for(i = 0; i < m.length(); ++i) {
            p = m[i] - '0';
            t = n[i] - '0';

            if(p + t + carry >= 10) {
                carry = 1;
                ++res;
            } else {
                carry = 0;
            }
        }

        while(i < n.length() && carry > 0) {
            t = n[i] - '0';
            if(t + carry >= 10) {
                carry = 1;
                ++res;
            } else {
                carry = 0;
            }
            ++i;
        }

        cout << res << endl;

    }

    return 0;
}
