
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
    
    int n;
    cin >> n;

    vector<int> arr(n);

    fori(i, n) cin >> arr[i];

    int q, t;
    cin >> q;

    long long v, p;
    v = p = 0;

    fori(i, q) {

        cin >> t;
       
        vector<int>::iterator it = find(arr.begin(), arr.end(), t); 
        int pos = distance(arr.begin(), it);

        v += pos+1;
        p += (n-pos);

    }

    cout << v << " " << p << endl;

    return 0;
}
