
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long h, l;
    
    cin >> h >> l;

    long double y = (long double)(h*h + l*l) / (long double) (2 * h);
    
    long double res = y * y - (long double) (l *l);

    res = sqrt(res);

    cout << setprecision(15) << res << "\n";

    return 0;
}
