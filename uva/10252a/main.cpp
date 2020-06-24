
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

    string res, a, b, tmp;

    int len;

    while(getline(cin, a)) {
        
        getline(cin, b);

        if(a.length() > b.length()) {
            tmp = a;
            a = b;
            b = tmp;
        }

        len = a.length();

        res = "";

        fori(i, len) {
            auto find = b.find(a[i]);
            if(find != string::npos) {
                res += a[i];
                b[(int) find] = '#';
            }
        }

        sort(all(res));

        cout << res << endl;

    }

    return 0;
}
