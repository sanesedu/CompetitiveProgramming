
#include <iostream>

using namespace std;

int main() {

    long long n;
    int k;

    cin >> n >> k;

    string s;

    for(int i = 0; i < k; ++i){
        s = to_string(n);
        if(s[s.length()-1] == '0'){
            n /= 10;
        } else {
            --n;
        }
    }

    cout << n << "\n";

    return 0;
}
