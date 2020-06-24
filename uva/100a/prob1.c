
#include <stdio.h>

int compute_cycle(int n)
{
    int count = 1;

    while(n > 1){
        if(n % 2 == 0){
            n /= 2;
        } else {
            n = 3*n + 1;
        }

        count++;
    }

    return count;
}

int max_cycle(int i, int j)
{
    if(i > j){
        return max_cycle(j, i);
    } 

    int max = 0;
    int k;

    for( k = i; k <= j; k++){
        int c = compute_cycle(k);
        max = (c > max)?c:max;
    }

    return max;
}

int main(int argc, char *argv[])
{
    int i, j;

    while(scanf("%d%d", &i, &j) == 2){
        //the & is used to pass the memory addresses of i and j so that scanf can modify them
        
        printf("%d %d %d\n", i, j, max_cycle(i, j));
    }

    
    return 0;
}
