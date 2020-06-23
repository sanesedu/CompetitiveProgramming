
#include <stdio.h>

using namespace std;

int main() {

    int n, h, g;

    scanf("%d", &n);

    int arr[n][2] = {};

    for(int i = 0; i < n; ++i){
        scanf("%d %d", &h, &g);
        arr[i][0] = h;
        arr[i][1] = g;
    }

    int res = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j && arr[i][0] == arr[j][1]){
                ++res;
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
