
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

int main() {

    int t, k, v, m, res;
    char c;
    string line;

    cin >> t;

    while(t--) {
        cin >> k;

        map<char, int> d;

        while(k--) {
            cin >> c >> v;
            d[c] = v;
        }

        cin >> m;

        cin.ignore();

        res = 0;

        while(m--) {
            getline(cin, line);

            for(int i = 0; i < (int) line.size(); ++i) {
                if(d.find(line[i]) != d.end()) res += d[line[i]];
            }
        }

        printf("%d.%02d$\n", res/100, res%100);
    }

    return 0;
}
