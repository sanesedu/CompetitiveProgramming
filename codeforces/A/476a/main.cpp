
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
    
    int n, m;
    cin >> n >> m;

    int mn = INT_MAX;

    forb(a, 0, n) {
        if((n-a) % 2 == 0) { //if steps left are even
            int b = (n-a)/2; //number of moves left with move 2
            if((a+b) % m == 0) mn = min(mn, a + b); 
        }
    }
    
    if(mn == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << mn << "\n";
    }
        
    return 0;
}
