
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool cmp(long long a, long long b) {
    if(a * b > 0) {
        return abs(a) > abs(b);
    } else {
        return a > b;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n;
    
    while(cin >> n) {
        if(n == 0) break;

        vector<long long> arr(n);

        fori(i, n) cin >> arr[i];

        sort(all(arr), cmp); 

        int i, j;
        i = 1;
        j = 2;
        
        long long res = arr[0] * arr[1];

        while(j < n) {
            res = max(res, arr[i++] * arr[j++]); 
        }
        
        cout << res << endl; 

    }

    return 0;
}
