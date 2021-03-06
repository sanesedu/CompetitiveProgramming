
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
    
    int n, a;
    cin >> n >> a;

    int arr[n] = {};

    fori(i, n) cin >> arr[i];

    int i, j;
    i = a - 2; //left iterator
    j = a; //right iterator

    int res = arr[a-1];

    while(i >= 0 || j < n) {
        if(i < 0) {
            res += arr[j];
        } else if(j >= n) {
            res += arr[i];
        } else {
            if(arr[i] & arr[j]) res += 2; 
        }
        --i;
        ++j;
    }

    cout << res << endl;

    return 0;
}
