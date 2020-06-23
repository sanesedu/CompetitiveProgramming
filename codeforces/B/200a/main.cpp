
#include <stdio.h>

using namespace std;

int main() {

    int n, temp;

    scanf("%d", &n);

    int total = 0;

    for(int i = 0; i < n; ++i){
        scanf("%d", &temp);
        total += temp;
    }

    double res = (double)total / n;

    printf("%f\n", res);

    return 0;
}
