
#include <iostream>

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

    long long b, c;

    for(int j = 0; j < q; ++j){
        
        cin >> a;

        if(a == 1){
            cin >> b >> c;
            
            arr[b-1] = c;

        } else {
            
            cin >> b;

            for(int k = 0; k < n; ++k){
                if(arr[k] < b) arr[k] = b;
            }
        }
    }

    for(int h = 0; h < n; ++h){
        cout << arr[h] << " ";
    }

    cout << "\n";

    return 0;
}
