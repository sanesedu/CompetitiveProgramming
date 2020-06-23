
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, temp;
    cin >> n >> k;

    int count = 0;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        if(temp + k <= 5) ++count;
    }

    cout << count/3 << endl;

    return 0;
}
