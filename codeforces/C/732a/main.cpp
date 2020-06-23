
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long b, d, s;
    cin >> b >> d >> s;

    long long a = max({b, d, s}) - 1; //if we leave or arrive at max, we stay max-1 complete days
    
    long long zero = 0; //fix error in max function

    long long res = max(zero, a-b) + max(zero, a-d) + max(zero, a-s);

    cout << res << "\n";

    return 0;
}
