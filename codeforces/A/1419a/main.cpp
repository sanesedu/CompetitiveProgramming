
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, n, winner;
    string num;

    bool found;

    cin >> t;

    while(t--) {
        cin >> n;
        cin >> num;
        
        found = false;

        if(n % 2 == 0) {
            //last digit will be on an even position, as the first removed digit is on an odd position
            //if at least one of the even position digits is even, Breach will win
            
            winner = 1;

            for(int i = 1; i < n && !found; i += 2) {
                if((num[i] - '0') % 2 == 0) {
                    found = true;
                    winner = 2;
                }
            }

        } else {
            //last digit will be on an odd position, as the first removed digit is on an odd position
            //if at least one of the odd position digits is odd, Raze will win
            
            winner = 2;

            for(int i = 0; i < n && !found; i += 2) {
                if((num[i] - '0') % 2 == 1) {
                    found = true;
                    winner = 1;
                }
            }

        }
    
        cout << winner << endl;
    }

    return 0;
}
