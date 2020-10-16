
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

    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
       
        if(n == 1 || n == 2 || n == 4) {
            cout << -1 << endl;
            continue;
        }

        if(n % 3 == 0) {
            printf("%d %d %d\n", n/3, 0, 0);
        } else if(n % 3 == 1) {
            printf("%d %d %d\n", (n-7)/3, 0, 1);
        } else {
            printf("%d %d %d\n", (n-5)/3, 1, 0);
        }
    }

    return 0;
}
