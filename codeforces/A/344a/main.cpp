
#include <stdio.h>

using namespace std;

int main() {

    int n, temp, prev;

    scanf("%d", &n);

    int groups = 0;

    scanf("%d", &prev);

    for(int i = 1; i < n; ++i){
        scanf("%d", &temp);
        if(temp != prev) ++groups;
        prev = temp;
    }

    ++groups;

    printf("%d\n", groups);

    return 0;
}
