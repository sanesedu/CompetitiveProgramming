
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
    
    int n, t;
    cin >> n;

    unordered_map<int, vector<int>> v;

    int one, two, three;
    one = two = three = 0;

    forb(i, 1, n) {
        cin >> t;
        v[t].pb(i);
        switch(t) {
            case 1:
                ++one;
                break;
            case 2:
                ++two;
                break;
            case 3:
                ++three;
                break;
        }
    } 

    int mn = min({one, two, three});

    cout << mn << "\n";        

    fori(i, mn) {
        cout << v[1][i] << " " << v[2][i] << " " << v[3][i] << "\n";
    }

    return 0;
}
