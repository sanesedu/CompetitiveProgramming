
#include <stdio.h>

using namespace std;

int main() {
    
    int n, a, b, c, res;

    res = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a + b + c >= 2) ++res;
    }

    printf("%d\n", res);

    return 0;
}
