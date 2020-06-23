
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

    int q, h, n;
    cin >> q;

    while(q--) {
        cin >> h >> n;

        int arr[n] = {};
        
        fori(i, n) cin >> arr[i];

        int res = 0;
        int p = 0;

        fori(i, n) {
            if(i > 0 && arr[i - 1] > arr[i] + 1) { //segment 11
                if(p > 0) { //not the initial platform
                    res += (i - p) & 1; //odd segment of 1s
                } else {
                    res += 1 - ((i - p) & 1); //even segment of 1s
                }
                p = i; //move prev 1 to this position
            }    
        }
        
        if(arr[n - 1] > 1) { //last element > 1
            if(p != 0) { 
                res += (n - p) & 1;
            } else {
                res += 1 - ((n - p) & 1);
            }
        }    

        cout << res << endl;

    }

    return 0;
}
