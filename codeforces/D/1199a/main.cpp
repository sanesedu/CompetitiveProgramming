
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q, a;

    cin >> n;

    long long arr[n] = {};

    for(int i = 0; i < n; ++i) cin >> arr[i];

    cin >> q;

    long long barr[q] = {};
    long long carr[n] = {};
    
    long long b, c;

    for(int j = 0; j < q; ++j){
        
        cin >> a;

        if(a == 1){
            cin >> b >> c;
            
            arr[b-1] = c;
            carr[b-1] = j;  //this way we connect carr with barr through the use of j

        } else {
            
            cin >> b;
            barr[j] = b;
        }
    }

    for(int k = q - 2; k >= 0; --k){
        barr[k] = max(barr[k], barr[k+1]); //we update the array of when case 2 occurs to reflect the biggest value. We build from end because only latest action matters
    }

    for(int h = 0; h < n; ++h){
        cout << max(arr[h], barr[carr[h]]) << " "; //arr[h] contains the greatest value given through case 1 action, and barr[carr[h]] contains the biggest value given through case 2 afterwards
    }

    cout << "\n";

    return 0;
}
