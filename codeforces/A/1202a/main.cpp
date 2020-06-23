
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;

    cin >> t;

    string a, b;

    for(long long i = 0; i < t; ++i) {
        cin >> a >> b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        long long bpos = b.find('1');
        long long apos = a.find('1', bpos);
        
        cout << apos - bpos << "\n";
    }

    return 0;
}
