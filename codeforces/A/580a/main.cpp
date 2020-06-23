
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int n;

    scanf("%d", &n);

    long long temp, prev;

    cin >> prev;

    int count = 1;
    int max = 1;

    for(int i = 1; i < n; ++i){
        cin >> temp;
        if(temp >= prev){
            ++count;
        } else {
            if(count > max) {
                max = count;
            }
            count = 1;
        }
        prev = temp;
    }

    if(count > max) max = count;

    printf("%d\n", max);

    return 0;
}
