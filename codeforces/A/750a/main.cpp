
#include <stdio.h>

using namespace std;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    k = 240 - k;

    int res = 0;

    for(int i = 1; i <= n; ++i) {
        k -= (5*i);
        if(k < 0) {
            break;
        } else {
            ++res;
        }
    }

    printf("%d\n", res);

    return 0;
}
