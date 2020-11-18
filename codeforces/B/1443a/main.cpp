
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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int t, a, b, res;
    string s;

    cin >> t;

    while(t--) {
        cin >> a >> b >> s;
        res = 0;
        
        int i, j;
        for(i = 0; i < s.size(); i = j) {
            // iterate a segment of the same values
            for(j = i + 1; j < s.size() && s[j] == s[i]; ++j) {}

            /* 
            starting point of segment was a mine and when the loop above ends, we have 2 options:
                - the end of the string has been reached, so we have a segment of consecutives mines and activating one activates all
                - we have reached a value of 0 but not the end of the string, but similarly there must be a segment of '1's ending here 
            */
            if(s[i] == '1') {
                res += a;
            /*
            starting point of the segment was an empty space, and not the first or last, we have 2 options:
                - we can fill the whole segment of '0's with mines
                - or do nothing
            */
            } else if(s[i] == '0' && i && j != s.size()) {
                res -= max(0, a - b * (j - i));
            }
        }

        cout << res << endl;
    }

    return 0;
}
