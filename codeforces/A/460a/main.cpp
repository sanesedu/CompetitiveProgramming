
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    long long res = 0;

    while(n > 0) {
        ++res;
        if(res % m == 0) ++n;
        --n;
    }

    cout << res << endl;

    return 0;
}
