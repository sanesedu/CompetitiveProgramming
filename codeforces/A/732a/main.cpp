
#include <stdio.h>

using namespace std;

int main() {

    int k, r;
    scanf("%d %d", &k, &r);

    int x;

    for(x = 1; x <= 10; ++x) {
        if((k*x % 10 == 0) || (k*x % 10 == r)) break;
    }

    printf("%d\n", x);

    return 0;
}
