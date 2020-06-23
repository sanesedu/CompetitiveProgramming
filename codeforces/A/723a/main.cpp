
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int res = max({a, b, c}) - min({a, b, c});

    cout << res << endl;

    return 0;
}
