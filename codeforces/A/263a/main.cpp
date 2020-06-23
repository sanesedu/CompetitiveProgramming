
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int temp, i, j;

    for(i = 0; i < 5; ++i){
        for(j = 0; j < 5; ++j){
            cin >> temp;
            if(temp == 1) break;
        }
        if(temp == 1) break;
    }

    int res = abs(i - 2) + abs(j - 2);

    cout << res << endl;

    return 0;
}
