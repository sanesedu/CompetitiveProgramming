
#include <stdio.h>
#include <iostream>

using namespace std;

bool is_prime(int n){
    if(n <= 3) {
        return true;
    } else if(n % 2 == 0){
        return false;
    } else{
        bool res = true;

        for(int i = 3; i < n/2 && res; ++i){
            if(n % i == 0) res = false;
        }

        return res;
    }
}

int main() {

    int n;

    scanf("%d", &n);

    int a, b;

    if(n % 2 == 0){
        a = n/2;
        b = n/2;
    } else {
        a = n/2;
        b = a + 1;
    }

    while(is_prime(a) || is_prime(b)){
        --a;
        ++b;
    }

    printf("%d %d\n", a, b);

    return 0;
}
