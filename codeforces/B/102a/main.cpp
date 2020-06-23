
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

    int l, sum, count;
    l = s.length();
    count = 0;

    while(l > 1) {
    
        sum = 0;
        ++count;

        fori(i, l) {
            sum += (s[i] - '0');
        }

        s = to_string(sum);
        l = s.length();
    }

    cout << count << endl;

    return 0;
}
