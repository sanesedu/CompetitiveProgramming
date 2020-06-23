
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
    
    string s;
    cin >> s;

    for(int i = 0; i < 1000; i += 8) { //generate the first 1000 multiples of 8
        int x = i;
        for(int j = s.size()-1; j >= 0; --j) {
            if(s[j]-'0' == x % 10) { //check if the number contains a subset of the digits of the current multiple of 8
                x /= 10;
                if(x == 0) {
                    cout << "YES\n" << i << "\n";
                    return 0;
                }
            }
        }
    }
    
    cout << "NO\n";
    
    return 0;

}
