
#include <stdio.h>

using namespace std;

int main() {

    int n, t;
    scanf("%d %d", &n, &t);

    int arr[n + 1] = {};

    for(int i = 1; i <= n; ++i) scanf("%d", &arr[i]);

    int x = 1;

    while(x < t) {
        x += arr[x];
    }

    if(x == t) printf("YES\n");
    else printf("NO\n");

    return 0;
}
