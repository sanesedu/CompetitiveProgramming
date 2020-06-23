
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
    
    string s;
    cin >> s;
    
    reverse(s.begin(), s.end());

    long long powers = 0;

    long long ones = 0;

    for(int i = 0; i < s.length(); ++i) {
        if(i % 2 == 0) ++powers;
        if(s[i] == '1') ++ones;
    }

    if(ones == 0) powers = 0;
    else if(ones == 1 && ((s.length()-1) % 2 == 0)) --powers;

    cout << powers << endl;

    return 0;
}
