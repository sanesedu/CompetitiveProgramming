
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
    
    int q, n, peaks, troughs;
    cin >> q;

    while(q--) {
        cin >> n;

        vector<int> arr(n);
        
        fori(i, n) cin >> arr[i];
    
        peaks = troughs = 0;

        for(int i = 1; i < n-1; ++i) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) ++peaks;
            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) ++troughs;
        }
    
        cout << peaks << " " << troughs << endl;
    }

    return 0;
}
