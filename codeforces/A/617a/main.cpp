
#include <stdio.h>

using namespace std;

int main() {

    int n;

    int steps = 0;

    scanf("%d", &n);

    while(n > 5){
        ++steps;
        n -= 5;
    }

    ++steps;

    printf("%d\n", steps);

    return 0;
}
