
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, temp;
    cin >> n;

    int res = 0;
    int min = 0;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        res += temp;

        if(res < min) {
            min = res;
        }
    }

    cout << abs(min) << endl;

    return 0;
}
