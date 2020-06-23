
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n;

    cin >> n;

    long long arr[n] = {};

    map<long long, long long> m, l;

    for(long long i = 0; i < n; ++i) {
        cin >> arr[i];
        m[arr[i]] = i;
    }

    long long p1 = -1, p2 = -1;

    long long sarr[n] = {};

    copy(arr, arr + n, sarr);

    sort(sarr, sarr + n);

    for(long long p = 0; p < n; ++p) {
        l[sarr[p]] = p;
    }

    long long even = 0;

    for(long long j = 0; j < n; ++j) {
        if(arr[j] != sarr[j]) {
            if(sarr[j] == arr[l[arr[j]]] && arr[j] == sarr[m[sarr[j]]]) {
                p1 = j;
                p2 = l[arr[j]];     
                break;         
            } else {
                cout << "no\n";
                return 0;
            }
        } 
    }

    for(long long j = p1+1; j < p2; ++j) {
        if(arr[j] != sarr[j]) {
            if(sarr[j] == arr[l[arr[j]]] && arr[j] == sarr[m[sarr[j]]]) {
            } else {
                cout << "no\n";
                return 0;
            }
        } else if(j == (p2+p1)/2){
        } else {
            cout << "no\n";
            return 0;
        }
    }

    for(long long m = p2 + 1; m < n; ++m) {
        if(sarr[m] != arr[m]) {
            cout << "no\n";
            return 0;
        }
    }

    cout << "yes\n";

    if(p1 == -1 && p2 == -1) p1 = p2 = 0;

    cout << p1+1 << " " << p2+1 << "\n";

    return 0;
}
