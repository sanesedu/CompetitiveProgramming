
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

class Automobile {
    public:
        string name;
        int lowest, highest;
        
        Automobile() {
            name = "";
            lowest = highest = -1;
        }

        Automobile(string n, int l, int h) {
            name = n;
            lowest = l;
            highest = h;
        }

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, c, q, l, h, p;
    string n, res;

    cin >> t;

    while(t--) {
        cin >> c;

        vector<Automobile> aes;

        fori(i, c) {
            cin >> n >> l >> h;
            aes.pb(*(new Automobile(n, l, h)));
        }

        cin >> q;

        while(q--) {
            cin >> p;
            res = "";

            fori(i, c) {
                if(p >= aes[i].lowest && p <= aes[i].highest) {
                    if(res == "") {
                        res = aes[i].name;
                    } else {
                        res = "UNDETERMINED";
                    }
                }
            }

            if(res == "") res = "UNDETERMINED";

            cout << res << endl;
        }

        if(t) cout << endl;
    }

    return 0;
}
