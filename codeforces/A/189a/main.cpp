
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {

    int n;
    int fix = 3;

    int vals[fix] = {};

    scanf("%d %d %d %d", &n, &vals[0], &vals[1], &vals[2]);

    int arr[n + 1];

    memset(arr, -1, sizeof(arr));

    arr[0] = 0;

    for(int i = 0; i < fix; ++i) {
        for(int j = vals[i]; j <= n; ++j) {
            if(arr[j-vals[i]] < 0) continue;
            arr[j] = max(arr[j], arr[j - vals[i]] + 1);
        }
    }

    printf("%d\n", arr[n]);

    return 0;
}
