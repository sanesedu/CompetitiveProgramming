
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

char solve(char c){
    if(c <= 'C') return '2';
    if(c <= 'F') return '3';
    if(c <= 'I') return '4';
    if(c <= 'L') return '5';
    if(c <= 'O') return '6';
    if(c <= 'S') return '7';
    if(c <= 'V') return '8';
    return '9';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    string line;

    int len, res;

    while(getline(cin, line)) {
        len = line.length();

        fori(i, len) {
            if(isalpha(line[i])) {
                cout << solve(line[i]);
            } else {
                cout << line[i];
            }
        }
        cout << endl;
    }

    return 0;
}
