
#include <stdio.h>

#define MAX_N 1000000U

static unsigned int cycle[MAX_N + 1];

unsigned int compute_cycle(unsigned int n)
{

    unsigned int count = 0;
    unsigned int k = n;

    while(n > 1){

        if(n < MAX_N && cycle[n] > 0){
            count = cycle[n] + count - 1;
            break;
        }

        if(n % 2 == 0){
            n /= 2;
        } else {
            n = 3*n + 1;
        }

        ++count;
    }

    ++count;

    cycle[k] = count;

    return count;
}

unsigned int max_cycle(unsigned int i, unsigned int j)
{
    if(i > j){
        return max_cycle(j, i);
    } 

    unsigned int max = 0;
    unsigned int k;

    for( k = i; k <= j; k++){
        unsigned int c = compute_cycle(k);
        max = (c > max) ? c : max;
    }

    return max;
}

unsigned int main(unsigned int argc, char *argv[])
{
    unsigned int i, j;

    cycle[1] = 1;

    for(i = 1, j = 1; i < MAX_N; i *= 2){
        cycle[i] = j++;
    }

    while(scanf("%u%u", &i, &j) == 2){
        printf("%u %u %u\n", i, j, max_cycle(i, j));
    }

    
    return 0;
}
