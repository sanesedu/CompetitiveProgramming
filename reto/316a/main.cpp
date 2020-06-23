
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
    
    int q, n, t;
    cin >> q;

    while(q--) {
        cin >> n;
        pair<int, int> prev, curr;
        int mx = -100000;
        int sum = 0;

        curr.first = 0;
        curr.first = 0;

        prev.first = 0;
        prev.second = 0;

        for(int i = 0; i < n; ++i) {
            cin >> t;
            sum += t;
            
            if(sum > mx) {
                prev.first = curr.first;
                prev.second = i;
                mx = sum;
            } else if(sum == mx) {
                if(i - curr.first < prev.second - prev.first) {
                    prev.first = curr.first;
                    prev.second = i;
                }
            } 

            if(sum <= 0) {
               sum = 0;
               curr.first = i+1; 
            } 
        }

        cout << prev.first + 1 << " " << prev.second + 1 << endl;

    }

    return 0;
}
