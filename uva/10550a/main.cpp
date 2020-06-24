
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

    int i, a, b, c;

    while(cin >> i >> a >> b >> c) {
        if(i == 0 && a == 0 && b == 0 && c == 0) break;
    
        int res = 80; //2 full turns
        
        //stop at first value
        res += (i - a + 40) % 40;

        res += 40; //counterclockwise full turn
   
        //counterclockwise to second value 
        res += (b - a + 40) % 40;

        //clockwise to third value    
        res += (b - c + 40) % 40;

        cout << res * 9  << endl;
    }

    return 0;
}
