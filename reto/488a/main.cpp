
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

    int cases, n, time;
    cin >> cases;

    while(cases--) {
        
        cin >> n >> time;

        int points[n];

        fori(i, n) cin >> points[i];

        int res = 1;
        int prev = 0;

        fori(i, n) {
            forb(j, i, n-1) { //try to take as many of the next save points as possible
                if(points[j] - prev > time) {
                    ++res;
                    i = j-1; //move until last element before greater than time
                    prev = points[j-1]; 
                    break;
                }
            }
        }

        cout << res << endl;

    }

    return 0;
}
