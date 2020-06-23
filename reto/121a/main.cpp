
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

    long long give, receive, have;

    bool b = true;

    while(b) {

        cin >> give >> receive >> have;

        if(give == 0 && receive == 0 && have == 0) {
            b = false;
            break;
        }

        if(receive >= give && have >= give) {
            cout << "RUINA\n";
            continue;
        }

        if(have < give || receive == 0) {
            cout << have << " " << have << endl;
            continue;
        }
        
        long long eats = have, packs = 0;

        while(have >= give) {
            packs = have/give;
            eats += packs*receive;
            have = (packs * receive + have % give);
        }
        
        cout << eats << " " << have << endl;
    }

    return 0;
}
