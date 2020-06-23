
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<int> arr;
int pos;

int solve() {

    ++pos;
    int node = arr[pos];

    if(node == 0) return 0;    

    int res = 0;
    
    fori(i, node) {
        res = max(res, solve());
    }

    return res + 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, t;
    cin >> q;

    string line;

    cin.ignore();

    while(q--) {
       
        getline(cin, line);
        
        stringstream ss(line);

        while(ss >> t) {
            arr.pb(t);
        }

        pos = -1;

        cout << solve() + 1 << endl;
        
        arr.clear();
    }

    return 0;
}
