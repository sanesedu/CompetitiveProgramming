
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
    
    int n;
    cin >> n;

    string s;

    fori(i, n) { 
        cin >> s;

        int col = 0;
        int row = 0;
        int cpos = 0;
        int type = false;

        if(s[0] == 'R') {i
            int digs = 0;
            forb(j, 1, s.length()-1) {
                if(isdigit(s[i])) ++digs;
                else cpos = j;
            }
            type = (digs == s.length() - 2) && (cpos != 0);
        }

        if(s[0] != 'R' || !type) {
            int mult = 1;
            for(int j = s.length()/2 -1; i >= 0; --i) {
                col += (s[j] - 'A')*mult;
                mult *= 26;
            }

            row = stoi(s.substr(s.length()/2, s.length()));

        } else {
            
            row = stoi(s.substr(1, cpos));
            
            int mult = 1;

        }

    }

    return 0;
}
