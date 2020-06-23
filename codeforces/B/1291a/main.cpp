
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

    int t, n, sufEnd, prefEnd;
    cin >> t;

    while(t--) {
        cin >> n;

        vector<int> arr(n);

        fori(i, n) cin >> arr[i];

        prefEnd = -1;
        sufEnd = n;
    
        for(int i = 0; i < n; ++i) {
            if(i > arr[i]) break; //push end of increasing array until value cannot be decreased until having value of its position
            prefEnd = i;
        }

        for(int i = n-1; i >= 0; --i) {
            if((n-1 - i) > arr[i]) break;
            sufEnd = i;
        }

        if(prefEnd >= sufEnd) { //there exists intersection between suf and pref subarrays
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
