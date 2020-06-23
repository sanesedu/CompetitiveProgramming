
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

    int cases;
    cin >> cases;

    long long hours;
    
    while(cases--) {
        
        cin >> hours;

        long long limit = 3599; //maximum number of spins/seconds in order to travel within the same hour

        long long res = hours + hours/limit; //hours to go back + extra hours to account for time spinning

        if(hours % limit == 0) --res; //it is exactly at the limit so it is within the hour

        cout << res << endl;
    }

    return 0;
}
