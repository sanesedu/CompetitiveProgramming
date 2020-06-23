
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp, min, max, minPos, maxPos;

    cin >> n;

    cin >> min;

    max = min;
    
    minPos = maxPos = 0;

    for(int i = 1; i < n; ++i){
        cin >> temp;

        if(temp > max){
            max = temp;
            maxPos = i;
        } else if(temp <= min){
            min = temp;
            minPos = i;
        }
    }

    int res = (maxPos - 0) + ((n - 1) - minPos);

    if(minPos < maxPos) --res;

    cout << res << "\n";

    return 0;
}
