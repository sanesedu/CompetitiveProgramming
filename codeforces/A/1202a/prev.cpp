
#include <iostream>
#include <bitset>
#include <cmath>
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

        bitset<64> x = bitset<64>(a);
        bitset<64> y = bitset<64>(b);

        string temp;

        string min = "";
        long long minpos = -1;

        for(long long j = 0; j <= a.length() + b.length(); ++j) {
            temp = bitset<64>(x.to_ullong() + pow(2, j)*y.to_ullong()).to_string();
            reverse(temp.begin(), temp.end());
            if(min == ""){
                min = temp;
                minpos = j;
            } else if(temp < min) {
                min = temp;
                minpos = j;
            }
        }

        cout << minpos << "\n";
    }

    return 0;
}
