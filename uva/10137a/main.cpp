
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    int lower, res, larger, smaller, upper, sum, n, dollar, cent, val;

    while(cin >> n) {
        if(n == 0) break;
    
        sum = 0;

        int arr[n] = {};

        fori(i, n) {
            scanf("%d.%d", &dollar, &cent);
            arr[i] = dollar * 100 + cent;
            sum += arr[i]; 
        }

        lower = sum/n;
        upper = ceil(1.0 * sum/n);
    
        smaller = larger = 0;

        fori(i, n) {
            if(arr[i] > upper) {
                larger += (arr[i] - upper); 
            } else if(arr[i] < lower) {
                smaller += (lower - arr[i]);
            }
        }

        res = max(smaller, larger);

        printf("$%d.%02d\n", res/100, res%100);
    }

    return 0;
}
