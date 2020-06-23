
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, a, b;
    cin >> n >> a >> b;

    if((a*b) >= (6*n)) {
        cout << a*b << "\n";
        cout << a << " " << b << "\n";
    } else {
        
        bool f = false;

        if(a > b) swap(a, b), f = true;

        long long res = 1e18, an, bn, temp;

        for(long long i = a; i*i <= 6*n; ++i) {

            temp = (6*n)/i; //value of b if a=i

            if(temp * i < 6*n) ++temp; //division not exact

            if(temp < b) continue; 

            if(temp * i < res) { //check for overflow
                res = temp * i;
                an = i;
                bn = temp;
            }
        }

        if(f) swap(an, bn);

        cout << res << "\n" << an << " " << bn << "\n";

    }

    return 0;
}
