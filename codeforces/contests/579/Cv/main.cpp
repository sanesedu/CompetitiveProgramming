
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, g, temp;
    cin >> n;
    
    cin >> g;

    for(long long i = 1; i < n; ++i) cin >> temp, g = __gcd(g, temp);

    temp = 1;

    long long res = 0;

    while(temp <= sqrt(g)) {
        
        if(g % temp == 0) {
            ++res;
            if(temp != sqrt(g)) ++res;
        }

        ++temp;
    }

    cout << res << endl;

    return 0;
}
