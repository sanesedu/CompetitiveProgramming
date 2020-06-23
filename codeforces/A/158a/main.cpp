
#include <stdio.h>

using namespace std;

int main() {
    
    int n, k, res, check, temp;

    scanf("%d %d", &n, &k);
    
    res = 0;

    for(int i = 1; i <= n; ++i){
        
        scanf("%d", &temp);

        if(i < k && temp > 0){
            ++res;
        } else if(i == k){
            check = temp;
            if(temp > 0) ++res;
        } else {
            if(temp == check && temp > 0){
                ++res;
            } else {
                break;
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
