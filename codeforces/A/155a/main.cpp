
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp; 
    cin >> n;

    int min, max;
    cin >> min;
    max = min;

    int res = 0;

    for(int i = 1; i < n; ++i) {
        cin >> temp;
        if(temp > max) {
            max = temp;
            ++res;
        } else if(temp < min) {
            min = temp;
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}
