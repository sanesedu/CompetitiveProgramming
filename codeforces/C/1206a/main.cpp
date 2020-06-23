
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    if(n % 2 == 0) {
        cout << "NO\n";
    } else {
        
        cout << "YES\n";

        int odd = 1;
        int even = 2*n;

        bool b = true;

        int res[2*n] = {};

        for(int i = 0; i < n; ++i) {
            if(b) {
                res[i] = odd;
                res[2*n-i-1] = even;
                b = false;
            } else {
                res[i] = even;
                res[2*n-i-1] = odd;
                b = true;
            }
            odd += 2;
            even -= 2;
        }

        for(int i = 0; i < 2*n; ++i) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}
