
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

char solve(char l, char r) {
    if(l == 'z') {
        if(r == 'a') return 'b';
        else if(r == 'b') return 'c';
        else return 'a';
    } else if(r == 'z') {
        if(l == 'a') return 'b';
        else if(l == 'b') return 'c';
        else return 'a';
    } else if(r == '?') {
        if(l == 'a') return 'b';
        else if(l == 'b') return 'c';
        else return 'a';
    } else {
        if(l == 'a' && r == 'a') return 'b';
        else if(l == 'b' && r == 'b') return 'c';
        else if(l == 'c'&& r == 'c') return 'a';
        else if((l == 'a' && r == 'b') || (l == 'b' && r == 'a')) return 'c'; 
        else if((l == 'a' && r == 'c') || (l == 'c' && r == 'a')) return 'b'; 
        else if((l == 'b' && r == 'c') || (l == 'c' && r == 'b')) return 'a'; 
        else return r;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int len, t;
    cin >> t;
    cin.ignore();

    string s;

    char prev;

    bool b;

    while(t--) {
        getline(cin, s);
    
        prev = 'z'; 
        
        len = s.length();
        
        b = true;

        for(int i = 0; i < len && b; ++i) {
            if(prev == s[i]) {
                b = false;
            } else if(s[i] == '?') {
                if(i == len -1) {
                    s[i] = solve(prev, 'z');
                } else {
                    s[i] = solve(prev, s[i+1]);
                }
            }
            prev = s[i];     
        }

        if(b) cout << s << endl;
        else cout << -1 << endl;
    }

    return 0;
}
