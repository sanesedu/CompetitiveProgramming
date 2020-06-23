
#include <stdio.h>

using namespace std;

int main() {
    
    int n, m;
    
    scanf("%d %d", &n, &m);

    int res = 0;

    while(m > n) {
        if(m % 2 == 0) m /= 2;
        else ++m;

        ++res;
    }

    printf("%d\n", res+n-m); //if n==m, result is res. but if m < n result will be the difference of n - m, as this difference will be cover with ++m

    return 0;
}
