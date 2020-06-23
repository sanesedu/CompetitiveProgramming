
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;

    cin >> q;

    long long a, b, c;

    for(int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        cout << (a + b + c)/2 << "\n";
    }

    return 0;
}
