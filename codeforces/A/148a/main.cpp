
#include <iostream>

using namespace std;

int main() {

    int k, l, m, n, d;

    cin >> k >> l >> m >> n >> d;

    int arr[d + 1] = {0};

    int iter = k;

    while(iter <= d){
        ++arr[iter];
        iter += k;
    }

    iter = l;

    while(iter <= d){
        ++arr[iter];
        iter += l;
    }

    iter = m;

    while(iter <= d){
        ++arr[iter];
        iter += m;
    }

    iter = n;

    while(iter <= d){
        ++arr[iter];
        iter += n;
    }

    int res = 0;

    for(int i = 1; i <= d; ++i){
        if(arr[i] != 0) ++res;
    }

    cout << res << endl;

    return 0;
}
