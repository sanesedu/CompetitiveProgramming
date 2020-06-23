
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    long long arr[n] = {};

    long long temp;

    cin >> arr[0];

    for(int i = 1; i < n; ++i) {
        cin >> temp;
        arr[i] = arr[0] + temp;
    }

    int i, j;

    long long res = 0;

    long long s1, s2, s3;

    for(i = 1; i < n - 1; ++i){
        s1 = arr[i-1];
        for(j = i; j < n - 1; ++j){
            s2 = arr[j] - s1;
            s3 = arr[n-1] - s2;

            cout << s1 << " " << s2 << " " << s3 << endl;

            if(s1 == s2 && s2 == s3) ++res;
        }
    }

    cout << res << "\n";

    return 0;
}
