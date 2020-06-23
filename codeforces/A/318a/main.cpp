
#include <iostream>

using namespace std;

int main() {
    
    long long n, k, res;

    cin >> n >> k;

    bool b;

    b = (n % 2 == 0 && k > n/2) || (n % 2 != 0 && k > n/2 + 1);

    if(b){
        if(n % 2 == 0) k -= n/2;
        else k -= (n/2 + 1);

        res = 2;

        for(long long i = 1; i < k; ++i){
            res += 2;
        }

    } else {
        res = 1;
        for(long long i = 1; i < k; ++i){
            res += 2;
        }

    }

    cout << res << endl;

    return 0;
}
