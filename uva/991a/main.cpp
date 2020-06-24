
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int memo[11] = {};

void catalan(int n) {

    memo[0] = 1;

    forb(i, 1, n) {
        memo[i] = (4*i - 2)*memo[i-1]/(i+1);
    }    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;

    catalan(10);

    int i = 0;

    while(cin >> n) {
        if(i) cout << endl;
        cout << memo[n] << endl;
        ++i;
    }

    return 0;
}
