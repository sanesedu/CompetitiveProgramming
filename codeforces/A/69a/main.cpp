
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    
    int n, x, y, z;
    int v[3] = {};

    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
    
        scanf("%d %d %d", &x, &y, &z);

        v[0] += x;
        v[1] += y;
        v[2] += z;
    }

    if(v[0] == 0 && v[1] == 0 && v[2] == 0){
        printf("%s\n", "YES");
    } else {
        printf("%s\n", "NO");
    }

    return 0;
}
