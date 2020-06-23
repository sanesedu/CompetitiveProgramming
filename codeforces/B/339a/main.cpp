
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, prev, temp;

    cin >> n >> m;

    cin >> prev;

    long long res = prev - 1;

    for(int i = 1; i < m; ++i){
        cin >> temp;
        if(temp >= prev) res += (temp - prev);
        else res += (n - prev) + temp;
        prev = temp;
    }

    cout << res << "\n";

    return 0;
}
