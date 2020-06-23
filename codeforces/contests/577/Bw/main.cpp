
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, temp;

    cin >> n;
    
    long long sum = 0;

    long long maxim = 0;

    for(long long i = 0; i < n; ++i) {
        cin >> temp;
        sum += temp;
        maxim = max(maxim, temp);
    }
    
    if(sum % 2 == 0 && (sum - maxim) >= maxim) {
        cout << "YES\n";
    } else {
       cout << "NO\n";
    }

    return 0;
}
