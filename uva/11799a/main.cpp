
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    
    int cases, creatures, max, temp;

    scanf("%d", &cases);

    for(int i = 1; i <= cases; i++){
        scanf("%d %d", &creatures, &max);
        
        for(int j = 1; j < creatures; j++){
            scanf("%d", &temp);
            if(temp > max){
                max = temp;
            }
        }

        printf("Case %d: %d\n", i, max);
    }

    return 0;
}
