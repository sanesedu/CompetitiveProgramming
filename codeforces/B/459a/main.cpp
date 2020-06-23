
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, i; 
    
    cin >> n;

    long long arr[n] = {};

    for(i = 0; i < n; ++i) cin >> arr[i];

    int size = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+size);

    long long max, temp;
    max = arr[n-1] - arr[0];

    long long count = 0;

    if(arr[n-1] == arr[0]){
   
        cout << max << " " << ((n*(n-1))/2) << "\n";

    } else {
        long long nmax, nmin;

        nmax = nmin = 0;

        for(i = 0; i < n; ++i){
            if(arr[i] == arr[0]) {
                ++nmin;
            } else if(arr[i] == arr[n-1]){
                ++nmax;
            }
        }

        cout << max << " " << nmax * nmin << "\n";
    }


    return 0;
}
