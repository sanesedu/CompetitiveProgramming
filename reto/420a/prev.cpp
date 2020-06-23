
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int ways(int sum, vector<int> arr, int i) {

//    cout << "pos: " << i << endl;

    if(sum == 0) return 1;

    if(sum < 0) return 0;

    if(i == (int) arr.size()) return 0;

    return ways(sum - arr[i], arr, i+1) + ways(sum, arr, i+1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, sum;
    cin >> q;

    string s;

    while(q--) {
        cin >> sum >> s;

        vector<int> arr;

        fori(i, s.length()) {
            if(s[i] - '0' > 0) arr.pb(s[i] - '0'); 
        }

        int res = ways(sum, arr, 0);
    
        cout << res << endl;
    }

    return 0;
}
