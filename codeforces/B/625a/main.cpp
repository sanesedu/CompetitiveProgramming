
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

void getLps(string pat, int *lps) {
    
    int i = 1;
    int j = 0;

    lps[0] = 0;

    int n = pat.length();

    while(i < n) {
        if(pat[i] == pat[j]) {
            ++j;
            lps[i] = j;
            ++i;
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }

}

int KMPSearch(string txt, string pat) {
    
    int m = txt.length();
    int n = pat.length();

    int lps[n];

    getLps(pat, lps);

    int i = 0;
    int j = 0;

    int res = 0;

    while(i < m) {
        if(pat[j] == txt[i]) {
            ++i;
            ++j;
        }

        if(j == n) {
            ++res;
            j = 0;
        } else if(i < m && pat[j] != txt[i]) {
            if(j != 0) {
                j = lps[j-1];
            } else {
                ++i;
            }
        }
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string txt, pat;
    cin >> txt >> pat;

    int res = KMPSearch(txt, pat);

    cout << res << endl;

    return 0;
}
