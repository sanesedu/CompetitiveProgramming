
#include <stdio.h>

using namespace std;

int main() {

    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);

    int res = 0;

    if(a > (b/m)) {
        res = b * (n/m);

        if((n%m) * a >= b) {
            res += b;
        } else {
            res += (n%m) * a;
        }

    } else {
        res = a * n;
    }

    printf("%d\n", res);

    return 0;
}
