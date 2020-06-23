
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    int n = min({a, c, d});

    long long res = (n * 256);

    a -= n;

    n = min(a, b);

    res += (n * 32);

    cout << res << "\n";

    return 0;
}
