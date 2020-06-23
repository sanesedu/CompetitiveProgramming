
#include <stdio.h>

using namespace std;

int main() {

    int n;

    scanf("%d", &n);

    int presses = 0;

    for(int i = 1; i < n; ++i){
        presses += (i * (n - i));
    }

    presses += n;

    printf("%d\n", presses);

    return 0;
}
