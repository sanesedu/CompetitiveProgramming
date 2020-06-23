
#include <stdio.h>

using namespace std;

int main() {

    int n, temp;

    scanf("%d", &n);

    int arr[n+1] = {0};

    for(int i = 1; i <=n; ++i){
        scanf("%d", &temp);
        arr[temp] = i;
    }

    for(int j = 1; j <=n; ++j){
        printf("%d ", arr[j]);
    }

    printf("\n");

    return 0;
}
