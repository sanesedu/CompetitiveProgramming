
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
typedef pair<int, int> pi;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int t, n, m, h, len;
    cin >> t;

    string line;

    while(t--) {
       
        cin >> n;
        cin.ignore();

        m = h = 0;

        getline(cin, line);

        len = line.length();

        fori(i, len) {    
            if(line[i] == 'H') ++h;
            else if(line[i] == 'M') ++m;
        }
        
        if(h == m) cout << "POSIBLE\n";
        else cout << "IMPOSIBLE\n";
    }

    return 0;
}
