
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
    
    int n, m, l, r;
    cin >> n >> m;

    bool arr[m+1] = {false};

    fori(i, n) {
        cin >> l >> r;
        forb(j, l, r) arr[j] = true;
    }

    vector<int> v;

    forb(i, 1,  m) {
        if(!arr[i]) v.pb(i);
    }

    cout << v.size() << endl;

    if(v.size() == 0) return 0;

    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); ++it) cout << *it << " ";

    cout << endl;

    return 0;
}
