
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

    string line;

    int tmp, len;

    while(getline(cin, line)) {
        len = line.length();

        for(int i = 0; i < len-1; i += 2) {
            tmp = (line[i] - '0') * 10 + (line[i+1] - '0');
            if(i + 2 < len && 10*tmp + (line[i+2] - '0') <= 122) {
                tmp = 10 * tmp + (line[i+2] - '0'); 
                ++i;
            }
            cout << (char) tmp;
        }
        cout << endl;
    }

    return 0;
}
