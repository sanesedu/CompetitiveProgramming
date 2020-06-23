
#include <iostream>

using namespace std;
 
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, s;
    cin >> m >> s;

    int k = s;

    if(m == 1 && s == 0) { //trivial
        cout << "0 0\n";
    } else if(s == 0 || s > 9 * m) { // sum 0 & length > 1 impossible. sum greater than maximum value for size impossible
        cout << "-1 -1\n";
    } else {
    
        for(int i = m - 1; i >= 0; --i) {
            
            int j = max(0, k - 9 * i); //we pick max of 0 and the rest of sum - maximum value possible at this point

            if(j == 0 && i == m - 1) //if this is the first digit, the smallest possible should be 1
                j = 1;
            cout << j;

            k -= j;
        }

        cout << " ";
        k = s;

        for(int i = m - 1; i >= 0; --i) {
            int j = min(9, k); //we pick min of 9 and remaining sum
     
            cout << j;
            k -= j;
        }
     
        cout << "\n"; 
    }

    return 0;
}
 
