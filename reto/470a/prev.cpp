
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

    ll r, a, v;

    stack<char> s;

    string line;

    int len;

    while(getline(cin, line)) {
        r = a = v = 0;
    
        len = line.length();

        fori(i, len) {
            if(line[i] == 'R') {
                ++r;
                s.push('R');
            } else if(line[i] == 'A') {
                if(a < r && s.top() != 'A') {
                    ++a;
                    s.push('A');
                }
            } else if(line[i] == 'V') {
                if(a > 0 && r > 0 && s.top() == 'A') {
                    --a;
                    --r;
                    ++v;
                    s.pop();
                    s.pop();
                }
            } else {
                r = a = 0;
                while(!s.empty()) s.pop();
            }
        }

        while(!s.empty()) s.pop();

        cout << v << endl;
    }

    return 0;
}
