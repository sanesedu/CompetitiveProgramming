
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool possible(int n) {

    while(n > 1) {
        if(n % 5 == 1) return true; //the number can be expressed as an addition of 5's + 1

        if(n % 3 == 0) n /= 3;
        else n -= 5;
    }

    return n == 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;
    bool b = true;

    while(b) {
        
        cin >> n;
        
        if(n == 0) {
            b = false;
            break;
        }

        if(possible(n)) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
