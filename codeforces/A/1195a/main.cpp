
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, temp;

    scanf("%d %d", &n, &k);

    int arr[k] = {0};

    for(int i = 0; i < n; ++i){
        scanf("%d", &temp);
        ++arr[temp - 1];
    } 
    
    int r = 0;
    int res = 0;

    for(int i = 0; i < k; ++i){
        temp = arr[i] % 2;
        r += temp;
        res += arr[i] - temp;
    }

    res += (r + 1) / 2;

    printf("%d\n", res);

    return 0;
}
