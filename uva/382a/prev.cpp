
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int sumDiv(int n) {
    
    int lim = sqrt(n);

    int sum = 1;

    for(int i = 2; i <= lim; ++i) {
        if(n % i == 0) {
            sum += (i + (n / i));
//            cout << "divs: " << i << " " << n/i << endl;
 //           cout << "sum: " << sum << endl;
        } 
    }

    return sum;
}

int main() {

    cout << "PERFECTION OUTPUT\n";

    int n;

    string s;

    while(cin >> n) {
        if(n == 0) break;    
    
        int sum = sumDiv(n);

        if(sum == n) {
            s = "PERFECT";
        } else if(sum < n) {
            s = "DEFICIENT";
        } else {
            s = "ABUNDANT";
        }

        printf("%5d  ", n);
        cout << s << endl;
    }

    cout << "END OF OUTPUT\n";
    
    return 0;
}
