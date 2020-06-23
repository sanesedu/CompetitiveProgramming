
#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    long long arr[n] = {};
    long long count[n] = {};
    
    long long temp, sum;

    cin >> arr[0];

    sum = arr[0];

    for(int i = 1; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum % 3 != 0) { //if the total sum is not divisible by 3, then we cannot form 3 groups with same value
        cout << 0 << "\n";
    } else {
        
        sum /= 3;

        temp = 0;

        for(int i = n-1; i >= 0; --i) {
            temp += arr[i];
            if(sum == temp) count[i] = 1;
        }

        for(int j = n - 2; j >= 0; --j) {
            count[j] += count[j+1];
        }

        long long res = 0;
        temp = 0;

        for(int k = 0; k < n - 2; ++k){
            temp += arr[k];
            if(temp == sum) res += count[k+2];
        }

        cout << res << "\n";
    }

    return 0;
}
