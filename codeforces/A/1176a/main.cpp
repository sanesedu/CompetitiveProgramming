
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin >> q;

    long long n, count2, count3, count5;

    for(int i = 0; i < q; ++i) {
        cin >> n;

        count2 = count3 = count5 = 0;

        while(n % 2 == 0) {
            ++count2;
            n /= 2;
        }

        while(n % 3 == 0) {
            ++count3;
            n /= 3;
        } 

        while(n % 5 == 0) {
            ++count5;
            n /= 5;
        }

        if(n != 1) cout << -1 << "\n";
        else cout << count2 + 2*count3 + 3*count5 << "\n"; //each div by 3 creates one more div by 2, each by 5 creates 2 more by 2
    }

    return 0;
}
