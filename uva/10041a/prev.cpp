
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int cases, p;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++){
        
        scanf("%d", &p);
        float total = 0;
        int temp, temp1;

        scanf("%d", &temp1);

        int k = temp1;

        total += temp1;

        for(int j = 1; j < p; j++){
            scanf("%d", &temp);
            total += temp;
        }
        
        float res = total / (float)p;
        
        int e = 0;

        if((int)round(res) % k == 0){
            e = (int)round(res);
        } else {
            e = (int)round(res-1);
        }

        printf("%d\n", e);
    }

    return 0;
}
