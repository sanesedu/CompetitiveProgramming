
#include <stdio.h>

using namespace std;

int main() {
    
    int exit, enter, n, max, total;

    total = max = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d %d", &exit, &enter);
        total -= exit;
        total += enter;
        if(total > max) max = total;
    }

    printf("%d\n", max);

    return 0;
}
