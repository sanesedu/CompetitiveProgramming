
#include <iostream>

using namespace std;

int main() {

    long long n;

    cin >> n;

    long long res = n / 2;

    if(n % 2 != 0){
        res -= n;
    }

    cout << res << endl;

    return 0;
}
