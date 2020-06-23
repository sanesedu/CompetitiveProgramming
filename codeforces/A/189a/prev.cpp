
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int fix = 3;

    int vals[fix] = {};

    scanf("%d %d %d %d", &n, &vals[0], &vals[1], &vals[2]);

    sort(vals, vals + fix);

    int arr[fix][n + 1] = {};

    for(int i = 0; i < fix; ++i) {
        for(int j = 1 ; j <= n; ++j) {
            
            if(j % vals[i] == 0) {
                arr[i][j] = j / vals[i];
            } else {
                arr[i][j] = 0;
            }
            
            if(i > 0 && j >= vals[i]){
                arr[i][j] = max(arr[i-1][j], 1 + arr[i-1][j-vals[i]]);
            }

            printf("%d ", arr[i][j]);
        }
      printf("\n");
    }

    printf("%d\n", arr[2][n]);

    return 0;
}
