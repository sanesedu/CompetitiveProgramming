
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

    int p, l, a, floor, total;
    char door;
    string s;

    while(cin >> p >> l >> a) {
        if(p == 0 && l == 0 && a == 0) break;

        map<string, int> m;

        fori(i, a) {
            cin >> floor >> door;
            s = to_string(floor) + door;
            m[s]++;
        }

        total = p*l;

        if(total % 2 == 1) ++total; 

        if((int) m.size() >= (total) / 2) cout << "EMPEZAMOS\n";
        else cout << "ESPERAMOS\n";
    }

    return 0;
}
