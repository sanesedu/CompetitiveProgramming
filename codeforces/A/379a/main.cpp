
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    long long res = 0;

    while(a > 0) {
        if(a >=b) {
            a -= b;
            res += b;
            ++a;    
        } else {
            res += a;
            a -= a;
        }
    }

    cout << res << endl;

    return 0;
}
