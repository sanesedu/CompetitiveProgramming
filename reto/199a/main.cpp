
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

    long long n;

    while(1) {

        cin >> n;

        if(n == 0) break;

        long long res = 0;

        switch(n % 4) {

            case 0:
            case 2:
                res = 20 * (long long) pow(30, (n/2 - 1));
                break;
            case 3:
                res = 100 * (long long) pow(500, (n/4));
                break;
            case 1:
                break;
        }

        cout << res << endl;

    }

    return 0;
}
