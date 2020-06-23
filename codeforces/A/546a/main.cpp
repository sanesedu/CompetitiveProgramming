
#include <stdio.h>

using namespace std;

int main() {

    int k, n, w;

    scanf("%d %d %d", &k, &n, &w);

    long long pay = k * (((w+1)*w)/2);

    if(pay > n){
        printf("%d\n", pay - n );
    } else {
        printf("%d\n", 0);
    }

    return 0;
}
