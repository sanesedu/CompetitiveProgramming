
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    cin >> n;

    bool easy = true;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        if(temp == 1) easy = false;
    }

    if(easy) cout << "EASY\n";
    else cout << "HARD\n";

    return 0;
}
