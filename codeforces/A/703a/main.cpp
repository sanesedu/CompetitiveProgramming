
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int m, c, t, r;
    m = c = 0;

    for(int i = 0; i < n; ++i) {
        cin >> t >> r;
        if(t > r) ++m;
        else if(r > t) ++c;
    }

    if(m > c) cout << "Mishka\n";
    else if (c > m) cout << "Chris\n";
    else cout << "Friendship is magic!^^\n";

    return 0;
}
