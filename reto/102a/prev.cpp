
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool isvowel(char c) {
    
    c = tolower(c);

    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string s;

    bool b = true;

    while(b) {
        
        getline(cin, s);

        int diff = 'p' - tolower(s[0]);

        int vowels = 0;

        fori(i, s.length()) {
            if(isalpha(s[i])){
                if(isupper(s[i])) {
                    if(s[i] + diff > 'Z') {
                        s[i] = 'A' + (diff + s[i] - 'Z') - 1;
                    } else if(s[i] + diff < 'A') {
                        s[i] = 'Z' + ('A' - (diff + s[i])) - 1;
                    } else {
                        s[i] += diff;
                    }
                } else {
                    if(s[i] + diff > 'z') {
                        s[i] = 'a' + (diff + s[i] - 'z') - 1;
                    } else if(s[i] + diff < 'a') {
                        s[i] = 'z' + ('a' - (diff + s[i])) - 1;
                    } else {
                        s[i] += diff;
                    }
                }
            }
            if(isvowel(s[i])) ++vowels;
        }
        
        if(s.compare("pFIN") == 0) b = false;
        else cout << vowels << endl;

    }

    return 0;
}
