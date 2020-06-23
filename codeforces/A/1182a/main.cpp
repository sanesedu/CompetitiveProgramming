
#include <stdio.h>

using namespace std;

int main() {

    int n; 

    scanf("%d", &n);

    if(n % 2 != 0) printf("%d\n", 0);
    else printf("%d\n", 1<<(n/2));        

    return 0;
}
