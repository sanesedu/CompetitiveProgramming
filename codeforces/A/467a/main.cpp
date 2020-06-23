
#include <stdio.h>

using namespace std;

int main() {

    int n, p, q, res;

    res = 0;
   
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d %d", &p, &q);
        if(q - p >= 2) res++;
    }

    printf("%d\n", res);

    return 0;
}
